#pragma once
#include "Node.h"
#include "Property.h"
#include "Boolean.h"
#include "Array.h"
#include "Object.h"
#include "String.h"
#include "Number.h"

class Parser {

public:

	Node* Parse(const std::string& json);

private:

	int _index;
	std::string _json;
	char _currentChar;

	Node* parseValue();
	Node* parseArray();
	Node* parseObject();
	Node* parseString();
	Node* parseNumber();

	void skipWhiteSpaces();

	void nextChar();

	bool consume(char expected);
};

