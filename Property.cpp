#include "Property.h"

Property::Property(const std::string& key, Node* value)
{
	_key = key;
	_value = value;
}
const std::string Property::getKey() const
{
	return _key;
}

Node* Property::getValue() const
{
	return _value;
}