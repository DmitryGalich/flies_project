#include "qml_engine_configurator.h"

QMLEngineConfigurator::QMLEngineConfigurator(QQmlContext* context,
                                             QObject* parent)
    : QObject(parent),
      context_(context),
      main_window_(new MainWindowHandler(this)) {}
