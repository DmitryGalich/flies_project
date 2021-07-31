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

 public:
  enum Roles { StupidityRole = Qt::UserRole + 1, NameRole };

  FliesModel(const std::string& qml_title,
             std::vector<Fly>& flies,
             const std::function<void()> run_session_function,
             const std::function<void()> stop_session_function,
             QObject* parent = nullptr);
  virtual ~FliesModel() override;

  int rowCount(const QModelIndex& parent = QModelIndex()) const override;
  QVariant data(const QModelIndex& index,
                int role = Qt::DisplayRole) const override;

 protected:
  Q_INVOKABLE void runSession();
  Q_INVOKABLE void stopSession();

  QHash<int, QByteArray> roleNames() const override;

 private:
  const std::function<void()> kRunSession_;
  const std::function<void()> kStopSession_;

  std::vector<Fly>& flies_;
};

#endif
