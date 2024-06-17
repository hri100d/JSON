#pragma once
#include "Node.h"


class Array : public Node {
private:
	std::vector<Node*> _elements;

public:
	virtual Type getType() const override;
	void addElement(Node* node);
	size_t getSize() const;
	Node* getElement(size_t index);
	virtual const std::vector<Node*>& getAllElementsAsArray() const override;

	virtual ~Array();
};

