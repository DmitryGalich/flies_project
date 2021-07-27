#include "qml_engine_configurator.h"

QMLEngineConfigurator::QMLEngineConfigurator(QQmlContext* context,
                                             QObject* parent)
    : QObject(parent), context_(context) {
  main_window_.reset(new MainWindowHandler("MainWindowHandler", this));
  context_->setContextProperty(main_window_->GetQmlTitle().c_str(),
                               main_window_.get());
}
