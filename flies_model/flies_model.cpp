#include "flies_model.h"

#include <iostream>

FliesModel::FliesModel(const std::string& qml_title,
                       FliesHolder& flies_holder,
                       const std::function<int()> request_cells_count,
                       QObject* parent)
    : QAbstractListModel(parent),
      AbstractQMLHandler(qml_title),
      kRequestCellsCount_(request_cells_count),
      flies_holder_(flies_holder) {}

FliesModel::~FliesModel() {
  stopSession();
}

int FliesModel::rowCount(const QModelIndex& parent) const {
  Q_UNUSED(parent);
  return flies_holder_.GetFliesCount();
}

QVariant FliesModel::data(const QModelIndex& index, int role) const {
  if (index.row() < 0 ||
      index.row() >= static_cast<int>(flies_holder_.GetFliesCount()))
    return QVariant();

  if (role == StupidityRole)
    return flies_holder_.GetFly(index.row()).GetStupidity();
  else if (role == NameRole)
    return flies_holder_.GetFly(index.row()).GetName().c_str();
  else if (role == AgeRole)
    return flies_holder_.GetFly(index.row()).GetAge();
  else if (role == CellRole)
    return flies_holder_.GetFly(index.row()).GetCellId();

  else if (role == IconRole)
    return flies_holder_.GetFly(index.row()).GetIconPath().c_str();

  else if (role == XRole)
    return flies_holder_.GetFly(index.row()).GetX();
  else if (role == YRole)
    return flies_holder_.GetFly(index.row()).GetY();
  else if (role == WidthRole)
    return flies_holder_.GetFly(index.row()).GetWidth();
  else if (role == HeightRole)
    return flies_holder_.GetFly(index.row()).GetHeight();

  else if (role == VisablityRole)
    return flies_holder_.GetFly(index.row()).GetVisability();

  else if (role == AliveRole)
    return flies_holder_.GetFly(index.row()).GetIsAlive();

  return QVariant();
}

bool FliesModel::setData(const QModelIndex& index,
                         const QVariant& value,
                         int role) {
  if (index.row() < 0 ||
      index.row() >= static_cast<int>(flies_holder_.GetFliesCount()))
    return false;

  if (role == RealXRole)
    flies_holder_.GetFly(index.row()).SetRealX(value.toInt());
  else if (role == RealYRole)
    flies_holder_.GetFly(index.row()).SetRealY(value.toInt());

  dataChanged(index, index, {RealXRole, RealYRole});

  return true;
}

void FliesModel::runSession() {
  if (!flies_holder_.Run())
    return;

  timer_.reset(new QTimer(this));
  timer_->setInterval(kFliesUpdatePeriodMilliseconds);
  connect(timer_.get(), &QTimer::timeout, [&]() {
    beginResetModel();
    endResetModel();
  });
  timer_->start();

  is_running_ = true;
  emit isRunningChanged();
}

void FliesModel::stopSession() {
  flies_holder_.Stop();

  if (!timer_)
    return;
  timer_->stop();
  timer_.reset();

  is_running_ = false;
  emit isRunningChanged();
}

void FliesModel::signalizeToOpenFlySettingsWindow() {
  emit openFlyAdditionWindow(Fly::GetDefaultName().c_str(),
                             kRequestCellsCount_() - 1, Fly::GetStupidityMax());
}

void FliesModel::addFly(QString name, int stupidity, int cell_id) {
  if (name.isEmpty())
    return;

  if (cell_id < 0 || cell_id >= kRequestCellsCount_())
    return;

  if (name.isEmpty())
    return;

  beginResetModel();
  auto status = flies_holder_.AddFly(name.toStdString(), stupidity, cell_id);
  if (status == FliesHolder::ErrorCodes::kWrongCell) {
    std::cout << "Wrong cell" << std::endl;
  }
  endResetModel();
}

QHash<int, QByteArray> FliesModel::roleNames() const {
  QHash<int, QByteArray> roles;

  roles[StupidityRole] = "flyStupidity";
  roles[NameRole] = "flyName";
  roles[AgeRole] = "flyAge";
  roles[CellRole] = "flyCell";

  roles[IconRole] = "flyIcon";

  roles[XRole] = "flyX";
  roles[YRole] = "flyY";

  roles[RealXRole] = "flyRealX";
  roles[RealYRole] = "flyRealY";

  roles[WidthRole] = "flyWidth";
  roles[HeightRole] = "flyHeight";

  roles[VisablityRole] = "flyVisible";
  roles[AliveRole] = "flyAlive";

  return roles;
}

bool FliesModel::getIsRunning() const {
  return is_running_;
}
