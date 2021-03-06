#ifndef _ANUBIS_WS_EXCEPTIONS_HH_
#define _ANUBIS_WS_EXCEPTIONS_HH_

#include <stdexcept>

namespace answer {

class WebMethodException: public std::runtime_error {
    int _error_level;

public:
    WebMethodException(const std::string& message, int error_level = 1002);
    int getErrorLevel() const;
};

class WebMethodInvalidInput: public WebMethodException {
public:
    WebMethodInvalidInput(const std::string& message);
};

class WebMethodMissingParameter: public WebMethodException {
public:
    WebMethodMissingParameter(const std::string& message);
};
}

#endif //_ANUBIS_WS_EXCEPTIONS_HH_