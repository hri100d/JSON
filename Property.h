#pragma once
#include "Node.h"


class Property {
private:
	std::string _key;
	Node* _value;

public:

	Property(const std::string& key, Node* value);
	const std::string getKey() const;

	Node* getValue() const;
};

