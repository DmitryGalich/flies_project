#ifndef BOARD_MODEL
#define BOARD_MODEL

#include <memory>

#include <QAbstractListModel>
#include <QObject>

#include "abstract_qml_handler.h"
#include "cell.h"

class BoardModel : public QAbstractListModel, public AbstractQMLHandler {
  Q_OBJECT

  Q_PROPERTY(
      int gridSide READ gridSide WRITE setGridSide NOTIFY gridSideChanged)

 signals:
  void gridSideChanged();

 public:
  enum Roles { CapacityRole = Qt::UserRole + 1 };

  BoardModel(const std::string& qml_title,
             std::vector<Cell>& cells,
             QObject* parent = nullptr);
  virtual ~BoardModel() override = default;

  int gridSide() const;
  void setGridSide(int value);

 protected:
  int rowCount(const QModelIndex& parent = QModelIndex()) const override;
  int columnCount(const QModelIndex& parent = QModelIndex()) const override;
  QVariant data(const QModelIndex& index,
                int role = Qt::DisplayRole) const override;
  QHash<int, QByteArray> roleNames() const override;

 private:
  std::vector<Cell>& cells_;
};

#endif
