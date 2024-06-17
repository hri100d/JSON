#pragma once
#include "Node.h"
#include "Property.h"

class Object : public Node {
private:
	std::vector<Property*> _elements;

public:

	virtual Type getType() const override;
	void addElement(const std::string& key, Node* value);
	Node* getElement(const std::string& key) const;
	virtual const std::vector<Property*>& getAllElementsAsObject() const override;

	virtual ~Object();
};
