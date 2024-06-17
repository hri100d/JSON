#include "Array.h"

Type Array::getType() const
{
	return ARRAY;
}
void Array::addElement(Node* node)
{
	_elements.push_back(node);
}
size_t Array::getSize() const
{
	return _elements.size();
}
Node* Array::getElement(size_t index)
{
	if (index > _elements.size())
	{
		return nullptr;
	}
	else
	{
		return _elements[index];
	}
}
const std::vector<Node*>& Array::getAllElementsAsArray() const
{
	return _elements;
}

Array::~Array()
{
	for (size_t i = 0; i < _elements.size(); i++)
	{
		Node* element = _elements[i];
		delete element;
	}
}