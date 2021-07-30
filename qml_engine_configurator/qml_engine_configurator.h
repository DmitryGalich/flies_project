#ifndef QML_ENGINE_CONFIGURATOR
#define QML_ENGINE_CONFIGURATOR

#include <memory>

#include <QObject>
#include <QQmlContext>

#include "board_model.h"
#include "cell_model.h"
#include "data_holder.h"

class QMLEngineConfigurator : public QObject {
  Q_OBJECT

 public:
  QMLEngineConfigurator(QQmlContext* context,
                        DataHolder& data_holder,
                        QObject* parent = nullptr);
  ~QMLEngineConfigurator() = default;

 private:
  QQmlContext* context_;

  std::unique_ptr<FliesModel> flies_model_;
  std::unique_ptr<BoardModel> board_model_;
};

#endif
