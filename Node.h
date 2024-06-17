#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

enum Type {

	BOOLEAN,
	NUMBER,
	STRING,
	ARRAY,
	OBJECT,
};

class Property;

class Node {

public:
	virtual Type getType() const = 0;
	virtual bool IsBoolean() const;
	virtual bool IsNumber() const;
	virtual bool IsString() const;
	virtual bool IsArray() const;
	virtual bool IsObject() const;

	virtual bool getAsBoolean() const;
	virtual double getAsNumber() const;
	virtual const std::string& getAsString() const;
	virtual const std::vector<Property*>& getAllElementsAsObject() const;
	virtual const std::vector<Node*>& getAllElementsAsArray() const;

	virtual ~Node();

};

