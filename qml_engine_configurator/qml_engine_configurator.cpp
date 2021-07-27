#include "qml_engine_configurator.h"

QMLEngineConfigurator::QMLEngineConfigurator(QQmlContext* context,
                                             DataHolder& data_holder,
                                             QObject* parent)
    : QObject(parent), context_(context) {
  main_window_.reset(new MainWindowHandler("MainWindowHandler", this));
  context_->setContextProperty(main_window_->GetQmlTitle().c_str(),
                               main_window_.get());

  flies_model_.reset(
      new FliesModel("FliesModel", data_holder.GetFlies(), this));
  context_->setContextProperty(flies_model_->GetQmlTitle().c_str(),
                               flies_model_.get());

  Fly fly(0);
  flies_model_->AddFly(fly);
  //  flies_model_->AddFly(Fly{1, this});
  //  flies_model_->AddFly(Fly{2, this});
  //  flies_model_->AddFly(Fly{3, this});
}
