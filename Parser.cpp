#include "Parser.h"

Node* Parser::Parse(const std::string& json) 
{
	_index = 0;
	_json = json;
	_currentChar = _json[_index];
	return parseValue();
}

Node* Parser::parseValue() 
{
	if (_index >= _json.size()) 
	{
		return nullptr;
	}
	_currentChar = _json[_index];
	while (consume(' '))
	{

	}

	char currentChar = _json[_index];
	if (currentChar == '[') {
		return parseArray();
	}
	else if (currentChar == '{')
	{
		return parseObject();
	}
	else if (isdigit(currentChar) || currentChar == '-') 
	{
		return parseNumber();
	}
	else if (currentChar == '\"') 
	{
		return parseString();
	}
	else if (currentChar == 't') 
	{
		_index += 4;
		return new Boolean(true);
	}
	else if (currentChar == 'f') 
	{
		_index += 5;
		return new Boolean(false);
	}

	return nullptr;
}

Node* Parser::parseArray() 
{
	consume('[');
	skipWhiteSpaces();

	Array* arr = new Array();

	// Check for empty array
	if (_currentChar == ']') 
	{
		consume(']');
		return arr;
	}

	while (true) 
	{
		arr->addElement(parseValue());
		skipWhiteSpaces();

		if (_currentChar == ',') 
		{
			consume(',');
			skipWhiteSpaces();
		}
		else if (_currentChar == ']') 
		{
			consume(']');
			break;
		}
		else 
		{
			throw std::runtime_error("Invalid JSON format: expected ',' or ']' in array");
		}
	}

	return arr;
}

Node* Parser::parseObject() 
{
	auto jsonObject = new Object();

	if (consume('{') == false) 
		throw std::runtime_error("Expected '{' at position " + std::to_string(_index));

	skipWhiteSpaces();

	if (consume('}')) 
		return jsonObject;
	

	do {
		skipWhiteSpaces();

		if (_currentChar != '"') 
			throw std::runtime_error("Expected '\"' at position " + std::to_string(_index));

		Node* key = parseString();

		skipWhiteSpaces();

		if (consume(':') == false)
			throw std::runtime_error("Expected ':' at position " + std::to_string(_index));

		skipWhiteSpaces();

		Node* value = parseValue();
		jsonObject->addElement(key->getAsString(), value);

		skipWhiteSpaces();

	} while (consume(','));

	if (consume('}') == false) 
		throw std::runtime_error("Expected '}' at position " + std::to_string(_index));
	

	return jsonObject;
}

Node* Parser::parseString()
{
	std::string value;
	consume('"');
	while (_currentChar != '"' && _index < _json.length())
	{
		value += _currentChar;
		consume(_currentChar);
	}
	consume('"');
	return new String(value);
}

Node* Parser::parseNumber() 
{
	std::string numberString = "";
	bool isNegative = false;
	if (_currentChar == '-')
	{
		isNegative = true;
		numberString += _currentChar;
		consume(_currentChar);
	}

	while (isdigit(_currentChar)) 
	{
		numberString += _currentChar;
		consume(_currentChar);
	}

	if (_currentChar == '.') 
	{
		numberString += _currentChar;
		consume(_currentChar);

		while (isdigit(_currentChar)) 
		{
			numberString += _currentChar;
			consume(_currentChar);
		}
	}

	if (_currentChar == 'e' || _currentChar == 'E') 
	{
		numberString += _currentChar;
		consume(_currentChar);

		if (_currentChar == '+' || _currentChar == '-') 
		{
			numberString += _currentChar;
			consume(_currentChar);
		}

		while (isdigit(_currentChar)) 
		{
			numberString += _currentChar;
			consume(_currentChar);
		}
	}

	try {
		double number = std::stod(numberString);
		if (isNegative) 
			number = -number;
		
		return new Number(number);
	}
	catch (const std::exception&) 
	{
		return nullptr;
	}
}

void Parser::skipWhiteSpaces() 
{
	while (std::isspace(_currentChar)) 
	{
		consume(' ');
	}
}

void Parser::nextChar() 
{
	if (_index < _json.size()) 
	{
		_index++;
		_currentChar = _json[_index];

	}
}

bool Parser::consume(char expected) 
{
	if (_currentChar == expected)
	{
		nextChar();
		return true;
	}

	return false;
}