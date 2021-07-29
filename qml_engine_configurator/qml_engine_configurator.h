#ifndef QML_ENGINE_CONFIGURATOR
#define QML_ENGINE_CONFIGURATOR

#include <memory>

#include <QObject>
#include <QQmlContext>

#include "cells_model.h"
#include "data_holder.h"
#include "flies_model.h"

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
  std::unique_ptr<CellsModel> cells_model_;
};

#endif
