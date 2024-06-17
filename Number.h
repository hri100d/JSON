#pragma once
#include "Node.h"

class Number : public Node {
private:
	double _value;

public:
	Number(double value);

	virtual Type getType() const override;
	double getValue() const;

	void setValue(double value);

	virtual double getAsNumber() const override;

	std::string toString() const;
};
