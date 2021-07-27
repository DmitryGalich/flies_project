#ifndef QML_ENGINE_CONFIGURATOR
#define QML_ENGINE_CONFIGURATOR

#include <memory>

#include <QObject>
#include <QQmlContext>

#include "main_window_handler.h"

class QMLEngineConfigurator : public QObject {
  Q_OBJECT

 public:
  QMLEngineConfigurator(QQmlContext* context, QObject* parent = nullptr);
  ~QMLEngineConfigurator() = default;

 private:
  QQmlContext* context_;

  std::unique_ptr<MainWindowHandler> main_window_;
};

#endif
