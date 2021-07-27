#include "main_window_handler.h"

MainWindowHandler::MainWindowHandler(const std::string& qml_title,
                                     QObject* parent)
    : QObject(parent), AbstractQMLHandler(qml_title) {}

MainWindowHandler::~MainWindowHandler() {}

void MainWindowHandler::playButtonClicked() {
  ProcessButtonVisability();
}

void MainWindowHandler::stopButtonClicked() {
  ProcessButtonVisability();
}

bool MainWindowHandler::getPlayButtonVisability() const {
  return play_button_visability_;
}

bool MainWindowHandler::getStopButtonVisability() const {
  return stop_button_visability_;
}

void MainWindowHandler::ProcessButtonVisability() {
  play_button_visability_ = !play_button_visability_;
  emit playButtonVisabilityChanged();
  stop_button_visability_ = !stop_button_visability_;
  emit stopButtonVisabilityChanged();
}
