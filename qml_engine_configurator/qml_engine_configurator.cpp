#include "qml_engine_configurator.h"

QMLEngineConfigurator::QMLEngineConfigurator(QQmlContext* context,
                                             SessionHandler& session_handler,
                                             QObject* parent)
    : QObject(parent), context_(context) {
  flies_model_.reset(new FliesModel("FliesModel", session_handler.GetFlies(),

                                    this));
  context_->setContextProperty(flies_model_->GetQmlTitle().c_str(),
                               flies_model_.get());

  board_model_.reset(
      new BoardModel("BoardModel", session_handler.GetCells(), this));
  context_->setContextProperty(board_model_->GetQmlTitle().c_str(),
                               board_model_.get());
}
