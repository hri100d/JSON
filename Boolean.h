#pragma once
#include "Node.h"


class Boolean : public Node
{
private:
	bool _value;

public:
	virtual Type getType() const override;
	Boolean(bool value);

	bool getValue() const;
	void setValue(bool value);
	virtual bool getAsBoolean() const override;
	std::string toString() const;
};

