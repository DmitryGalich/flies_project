#ifndef MAIN_WINDOW_HANDLER
#define MAIN_WINDOW_HANDLER

#include <QObject>

#include "abstract_qml_handler.h"

class MainWindowHandler : public QObject, public AbstractQMLHandler {
  Q_OBJECT

  Q_PROPERTY(bool playButtonVisability READ getPlayButtonVisability NOTIFY
                 playButtonVisabilityChanged)
  Q_PROPERTY(bool stopButtonVisability READ getStopButtonVisability NOTIFY
                 stopButtonVisabilityChanged)

 signals:
  void playButtonVisabilityChanged();
  void stopButtonVisabilityChanged();

 public:
  MainWindowHandler(const std::string& qml_title, QObject* parent = nullptr);
  virtual ~MainWindowHandler() override;

 protected:
  Q_INVOKABLE void playButtonClicked();
  Q_INVOKABLE void stopButtonClicked();

  bool getPlayButtonVisability() const;
  bool getStopButtonVisability() const;

 private:
  void ProcessButtonVisability();

  bool play_button_visability_{true};
  bool stop_button_visability_{false};
};

#endif
