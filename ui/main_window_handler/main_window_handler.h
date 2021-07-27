#ifndef MAIN_WINDOW_HANDLER
#define MAIN_WINDOW_HANDLER

#include <QObject>

class MainWindowHandler : public QObject {
  Q_OBJECT

 public:
  MainWindowHandler(QObject* parent = nullptr);
  virtual ~MainWindowHandler();
};

#endif
