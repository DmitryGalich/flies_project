#ifndef FLIES_MODEL
#define FLIES_MODEL

#include <memory>

#include <QAbstractListModel>
#include <QObject>

#include "abstract_qml_handler.h"
#include "fly.h"

class FliesModel : public QAbstractListModel, public AbstractQMLHandler {
  Q_OBJECT

  Q_PROPERTY(int fliesCount READ getFliesCount NOTIFY fliesCountChanged)

 signals:
  void fliesCountChanged();

 public:
  enum AnimalRoles { StupidityRole = Qt::UserRole + 1, NameRole };

  FliesModel(const std::string& qml_title,
             std::vector<Fly>& flies,
             QObject* parent = nullptr);
  virtual ~FliesModel() override;

  int rowCount(const QModelIndex& parent = QModelIndex()) const override;
  QVariant data(const QModelIndex& index,
                int role = Qt::DisplayRole) const override;

 protected:
  Q_INVOKABLE void setFlyStupidity(const int index, const int stupidity);
  Q_INVOKABLE void setFlyName(const int index, const QString& name);
  Q_INVOKABLE void setFliesCount(const int count);

  int getFliesCount() const;

  QHash<int, QByteArray> roleNames() const override;

  std::vector<Fly>& flies_;
};

#endif
