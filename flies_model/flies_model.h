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
  void openFlyAdditionWindow();

 public:
  enum Roles { StupidityRole = Qt::UserRole + 1, NameRole };

  FliesModel(const std::string& qml_title,
             std::vector<Fly>& flies,
             QObject* parent = nullptr);
  virtual ~FliesModel() override;

  int rowCount(const QModelIndex& parent = QModelIndex()) const override;
  QVariant data(const QModelIndex& index,
                int role = Qt::DisplayRole) const override;

 protected:
  Q_INVOKABLE void runSession();
  Q_INVOKABLE void stopSession();

  Q_INVOKABLE void addFly();

  QHash<int, QByteArray> roleNames() const override;

 private:
  std::vector<Fly>& flies_;
};

#endif
