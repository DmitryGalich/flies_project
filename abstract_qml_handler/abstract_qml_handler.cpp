#include "abstract_qml_handler.h"

AbstractQMLHandler::AbstractQMLHandler(const std::string& qml_title)
    : kQMLTitle_{qml_title} {}

AbstractQMLHandler::~AbstractQMLHandler() {}

const std::string& AbstractQMLHandler::GetQmlTitle() const {
  return kQMLTitle_;
}
