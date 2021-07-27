#ifndef ABSTRACT_QML_HANDLER
#define ABSTRACT_QML_HANDLER

#include <string>

class AbstractQMLHandler {
 public:
  AbstractQMLHandler(const std::string& qml_title);
  virtual ~AbstractQMLHandler();

  const std::string& GetQmlTitle() const;

 protected:
  const std::string kQMLTitle_;
};

#endif
