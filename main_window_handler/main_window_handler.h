#ifndef MAIN_WINDOW_HANDLER
#define MAIN_WINDOW_HANDLER

#include <QObject>

#include "abstract_qml_handler.h"

class MainWindowHandler : public QObject, public AbstractQMLHandler {
  Q_OBJECT
 public:
  MainWindowHandler(const std::string& qml_title, QObject* parent = nullptr);
  virtual ~MainWindowHandler() override;
};

#endif
