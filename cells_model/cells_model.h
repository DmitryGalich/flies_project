#ifndef CELLS_MODEL
#define CELLS_MODEL

#include <memory>

#include <QAbstractListModel>
#include <QObject>

#include "abstract_qml_handler.h"
#include "board.h"
#include "cell.h"

class CellsModel : public QAbstractListModel, public AbstractQMLHandler {
  Q_OBJECT

  Q_PROPERTY(int cellsCount READ getCellsCount NOTIFY cellsCountChanged)

 signals:
  void cellsCountChanged();

 public:
  enum AnimalRoles { CapacityRole = Qt::UserRole + 1 };

  CellsModel(const std::string& qml_title,
             std::vector<std::vector<Cell>>& cells,
             QObject* parent = nullptr);
  virtual ~CellsModel() override = default;

  int rowCount(const QModelIndex& parent = QModelIndex()) const override;
  QVariant data(const QModelIndex& index,
                int role = Qt::DisplayRole) const override;

 protected:
  QHash<int, QByteArray> roleNames() const override;

  int getCellsCount() const;

  void ConvertToCellsList();

  std::vector<std::vector<Cell>>& cells_;
  std::vector<Cell*> cells_list_;
};

#endif
