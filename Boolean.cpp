#include "Boolean.h"


Type Boolean::getType() const
{
	return BOOLEAN;
}
Boolean::Boolean(bool value)
{
	_value = value;
}

bool Boolean::getValue() const
{
	return _value;
}
void Boolean::setValue(bool value)
{
	_value = value;
}
bool Boolean::getAsBoolean() const
{
	return _value;
}
std::string Boolean::toString() const {
	if (_value)
	{
		return "true";
	}
	return "false";
}