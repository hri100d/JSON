#include "Object.h"

Type Object::getType() const
{
	return OBJECT;
}
void Object::addElement(const std::string& key, Node* value)
{
	Property* temp = new Property(key, value);
	_elements.push_back(temp);
}
Node* Object::getElement(const std::string& key) const
{
	for (int i = 0; i < _elements.size(); i++)
	{
		Property* temp = _elements[i];
		if (temp->getKey() == key)
		{
			return temp->getValue();
		}
	}

	return nullptr;
}
const std::vector<Property*>& Object::getAllElementsAsObject() const
{
	return _elements;
}

Object::~Object() {
	for (size_t i = 0; i < _elements.size(); i++) {
		Property* element = _elements[i];
		delete element->getValue();
		delete element;
	}
}