#include "Number.h"

Number::Number(double value)
{
	_value = value;
}

Type Number::getType() const
{
	return NUMBER;
}

double Number::getValue() const
{
	return _value;
}

void Number::setValue(double value)
{
	_value = value;
}

double Number::getAsNumber() const
{
	return _value;
}

std::string Number::toString() const
{
	return std::to_string(_value);
}