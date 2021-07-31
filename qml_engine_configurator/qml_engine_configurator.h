#ifndef QML_ENGINE_CONFIGURATOR
#define QML_ENGINE_CONFIGURATOR

#include <memory>

#include <QObject>
#include <QQmlContext>

#include "board_model.h"
#include "flies_model.h"
#include "session_handler.h"

class QMLEngineConfigurator : public QObject {
  Q_OBJECT

 public:
  QMLEngineConfigurator(QQmlContext* context,
                        SessionHandler& session_handler,
                        QObject* parent = nullptr);
  ~QMLEngineConfigurator() = default;

 private:
  QQmlContext* context_;

  std::unique_ptr<FliesModel> flies_model_;
  std::unique_ptr<BoardModel> board_model_;
};

#endif
