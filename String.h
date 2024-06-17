#pragma once
#include "Node.h"

class String : public Node {
private:
	std::string _value;

public:
	virtual Type getType() const override;

	String(const std::string& value);
	const std::string& getValue() const;
	void setValue(const std::string& value);
	virtual const std::string& getAsString() const override;
};
