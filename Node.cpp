#include "Node.h"

bool Node::IsBoolean() const
{
	return getType() == BOOLEAN;
}
bool Node::IsNumber() const
{
	return getType() == NUMBER;
}
bool Node::Node::IsString() const
{
	return getType() == STRING;
}
bool Node::IsArray() const
{
	return getType() == ARRAY;
}
bool Node::IsObject() const
{
	return getType() == OBJECT;
}

bool Node::getAsBoolean() const
{
	return false;
}
double Node::getAsNumber() const
{
	return 0.0;
}
const std::string& Node::getAsString() const
{
	std::string empty;
	return empty;
}
const std::vector<Property*>& Node::getAllElementsAsObject() const
{
	std::vector<Property*> empty;
	return empty;
}
const std::vector<Node*>& Node::getAllElementsAsArray() const
{
	std::vector<Node*> empty;
	return empty;
}
Node::~Node()
{

}