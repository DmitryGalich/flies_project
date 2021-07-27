#include "main_window_handler.h"

MainWindowHandler::MainWindowHandler(const std::string& qml_title,
                                     QObject* parent)
    : QObject(parent), AbstractQMLHandler(qml_title) {}

MainWindowHandler::~MainWindowHandler() {}
