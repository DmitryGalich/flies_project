#include "qml_engine_configurator.h"

QMLEngineConfigurator::QMLEngineConfigurator(QQmlContext* context,
                                             DataHolder& data_holder,
                                             QObject* parent)
    : QObject(parent), context_(context) {
  //  main_window_.reset(new MainWindowHandler("MainWindowHandler", this));
  //  context_->setContextProperty(main_window_->GetQmlTitle().c_str(),
  //                               main_window_.get());

  //  flies_model_.reset(
  //      new FliesModel("FliesModel", data_holder.GetFlies(), this));
  //  context_->setContextProperty(flies_model_->GetQmlTitle().c_str(),
  //                               flies_model_.get());

  cells_model_.reset(
      new CellsModel("CellsModel", data_holder.GetCells(), this));
  context_->setContextProperty(cells_model_->GetQmlTitle().c_str(),
                               cells_model_.get());
}
