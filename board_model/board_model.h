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
  void signalTopenCellSettingWindow(const int cell_index,
                                    const int current_capacity);

 public:
  enum Roles {
    CellFliesRole = Qt::UserRole + 1,
    CellXRole,
    CellYRole,
    CellWidthRole,
    CellHeightRole,
    CellCapacitytRole
  };

  BoardModel(const std::string& qml_title,
             CellsHolder& cells,
             QObject* parent = nullptr);
  virtual ~BoardModel() override = default;

  int gridSide() const;
  void setGridSide(int value);

 protected:
  int rowCount(const QModelIndex& parent = QModelIndex()) const override;
  int columnCount(const QModelIndex& parent = QModelIndex()) const override;

  QVariant data(const QModelIndex& index,
                int role = Qt::DisplayRole) const override;
  bool setData(const QModelIndex& index,
               const QVariant& value,
               int role = Qt::EditRole) override;

  QHash<int, QByteArray> roleNames() const override;

  Q_INVOKABLE void openCellSettingsWindow(const int cell_index);
  Q_INVOKABLE void setCellCapacity(const int cell_index, const int value);
  Q_INVOKABLE void updateModel();

 private:
  CellsHolder& cells_holder_;
};

#endif
