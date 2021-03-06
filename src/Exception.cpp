#include "answer/Exception.hh"


using namespace std;

namespace answer{

WebMethodException::WebMethodException(const std::string& message, int error_level)
	: std::runtime_error(message), _error_level(error_level) { }
	
	
int WebMethodException::getErrorLevel() const { return _error_level; }

WebMethodInvalidInput::WebMethodInvalidInput(const std::string& message)
	: WebMethodException(message, 1003){ }

WebMethodMissingParameter::WebMethodMissingParameter(const std::string& message)
	: WebMethodException(message, 1010){ }
	
}