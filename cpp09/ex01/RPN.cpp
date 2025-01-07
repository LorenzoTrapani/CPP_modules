#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const &src) {
	*this = src;
}

RPN &RPN::operator=(RPN const &src) {
	if (this != &src) {
		_stack = src._stack;
	}
	return *this;
}

RPN::~RPN() {}

int stringToInt(const std::string& str)
{
    std::istringstream iss(str);
    int value;
    iss >> value;
    return value;
}

void RPN::handleInput(std::string const &str) {
    std::istringstream iss(str);
    std::string token;
    std::string ops = "+-*/%";

    while (iss >> token) {
        if (token.length() == 1 && ops.find(token[0]) != std::string::npos)
            calculate(token[0]);
        else if(token.length() ==1 && !isdigit(token[0]))
            _stack.push(stringToInt(token));
        else
            throw std::runtime_error("Error: Invalid token");
        }
        if (_stack.size() != 1)
            throw std::runtime_error("Error: Invalid expression");   
        std::cout << "Result: " << _stack.top() << std::endl;
        _stack.pop();
}

void RPN::calculate(char op) {
	if (_stack.size() < 2)
		throw std::runtime_error("Error: Not enough values in stack");
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	switch (op) {
		case '+':
			_stack.push(b + a);
			break;
		case '-':
			_stack.push(b - a);
			break;
		case '*':
			_stack.push(b * a);
			break;
		case '/':
			if (a == 0)
				throw std::runtime_error("Error: Division by zero");
			_stack.push(b / a);
			break;
	}
}


