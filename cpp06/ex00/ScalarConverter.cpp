#include "ScalarConverter.hpp"

#include <iostream>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cmath>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    (void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &assign)
{
    (void)assign;
    return (*this);
}

void ScalarConverter::printSpecial(const std::string &c, const std::string &i, const std::string &f, const std::string &d) {
    std::cout << "Char: " << c << std::endl;
    std::cout << "Int: " << i << std::endl;
    std::cout << "Float: " << f << std::endl;
    std::cout << "Double: " << d << std::endl;
}

void ScalarConverter::printChar(char c, char type) {
    if (type == 'c')
		std::cout << "Char: '" << c << "'" << std::endl;
	else if (type == 'i') {
		if (c >= 32 && c <= 126)
    	    std::cout << "Char: " << (c) << std::endl;
    	else
    	    std::cout << "Char: Non displayable\n";
    }
	else if (type == 'f') {
		if (!std::isprint(c) || std::fmod(c, 1) == 0.0f)
    	    std::cout << "Char: impossible" << std::endl;
    	else
    	    std::cout << "Char: " << (c) << std::endl;
	}
	else if (type == 'd') {
		if (!std::isprint(c) || std::fmod(c, 1) != 0.0)
        std::cout << "Char: impossible" << std::endl;
	else
        std::cout << "Char: " << (c) << std::endl;
	}
}


bool ScalarConverter::isSpecialValue(const std::string &input)
{
    return (input == "+inf" || input == "-inf" || input == "nan" ||
            input == "+inff" || input == "-inff" || input == "nanf");
}

bool ScalarConverter::isChar(const std::string &input)
{
    return (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]));
}

bool ScalarConverter::isInt(const std::string &input)
{
	std::stringstream ss(input);
	int i;
	ss >> i;
	if (ss.fail() || !ss.eof())
		return (false);
	return (true);
}

bool ScalarConverter::isFloat(const std::string &input)
{
    return (input[input.length() -1] == 'f' && isDisplayable(input.substr(0, input.length() - 1)));
}

bool ScalarConverter::isDouble(const std::string &input)
{
    return (input.find('.') != std::string::npos && isDisplayable(input));
}

bool ScalarConverter::isDisplayable(const std::string &input) {
    if (input.empty()) {
        return false;
    }

    bool dotSeen = false;
    size_t len = input.length();

    for (size_t i = 0; i < len; ++i) {
        char ch = input[i];

        if (i == 0 && (ch == '+' || ch == '-'))
            continue;

        if (ch == '.') {
            if (dotSeen || i == 0 || i == len - 1 || !isdigit(input[i - 1]) || !isdigit(input[i + 1]))
                return false;
            dotSeen = true;
            continue;
        }

        if (ch == 'f' && i == len - 1)
            continue;

        if (!isdigit(ch))
            return false;
    }
    return true;
}

void ScalarConverter::convertChar(const std::string &input)
{
    char c = input[0];
    printChar(c, 'c');
    std::cout << "Int: " << static_cast<int>(c) << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertInt(const std::string &input)
{
    int i = strtol(input.c_str(), NULL, 10);
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    printChar(c, 'i');
    std::cout << "Int: " << i << std::endl;
    std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convertFloat(const std::string &input)
{
    float f = strtof(input.c_str(), NULL);
    char c = static_cast<char>(f);
    int i = static_cast<int>(f);
    double d = static_cast<double>(f);

    printChar(c, 'f');
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convertDouble(const std::string &input)
{
    double d = strtod(input.c_str(), NULL);
    char c = static_cast<char>(d);
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);

    printChar(c, 'd');
	std::cout << "Int: " << i << std::endl;
    std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::handleSpecialValue(const std::string &input)
{
	if (input == "nan" || input == "nanf")
		printSpecial("impossible", "impossible", "nanf", "nan");
	else if (input == "+inf" || input == "-inf")
		printSpecial("impossible", "impossible", input + "f", input);
	else if (input == "+inff" || input == "-inff")
		printSpecial("impossible", "impossible", input, input.substr(0, input.length() - 1));
}

void ScalarConverter::convert(std::string input)
{
    if (isSpecialValue(input))
	{
		handleSpecialValue(input);
		return;
	}
    if (isChar(input))
        convertChar(input);
    else if (isInt(input))
        convertInt(input);
    else if (isFloat(input))
        convertFloat(input);
    else if (isDouble(input))
        convertDouble(input);
    else
        std::cerr << "Invalid input" << std::endl;
}
