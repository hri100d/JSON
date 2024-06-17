#include "String.h"


Type String::getType() const
{
	return STRING;
}

String::String(const std::string& value)
{
	_value = value;
}
const std::string& String::getValue() const
{
	return _value;
}
void String::setValue(const std::string& value)
{
	_value = value;
}
const std::string& String::getAsString() const
{
	return _value;
}