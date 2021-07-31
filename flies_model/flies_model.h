#ifndef FLIES_MODEL
#define FLIES_MODEL

#include <functional>
#include <memory>

#include <QAbstractListModel>
#include <QObject>

#include "abstract_qml_handler.h"
#include "fly.h"

class FliesModel : public QAbstractListModel, public AbstractQMLHandler {
  Q_OBJECT

 signals:
  void openFlyAdditionWindow(QString default_name,
                             int cells_max,
                             int stupidity_max);

 public:
  enum Roles { StupidityRole = Qt::UserRole + 1, NameRole, AgeRole, CellRole };

  FliesModel(const std::string& qml_title,
             std::vector<Fly>& flies,
             const std::function<int()> request_cells_count,
             QObject* parent = nullptr);
  virtual ~FliesModel() override;

  int rowCount(const QModelIndex& parent = QModelIndex()) const override;
  QVariant data(const QModelIndex& index,
                int role = Qt::DisplayRole) const override;

 protected:
  Q_INVOKABLE void runSession();
  Q_INVOKABLE void stopSession();
  Q_INVOKABLE void signalizeToOpenFlySettingsWindow();
  Q_INVOKABLE void addFly(QString default_name, int stupidity, int cell_id);

  QHash<int, QByteArray> roleNames() const override;

 private:
  const std::function<int()> kRequestCellsCount_;
  std::vector<Fly>& flies_;
};

#endif
