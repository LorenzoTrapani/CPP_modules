#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <cctype>
#include <exception>


class ScalarConverter
{
public:
	static void convert(std::string input);
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &assign);
	~ScalarConverter();

	static bool isSpecialValue(const std::string &input);	
	static bool isChar(const std::string &input);
	static bool isInt(const std::string &input);
	static bool isFloat(const std::string &input);
	static bool isDouble(const std::string &input);

    static void convertChar(const std::string &input);
    static void convertInt(const std::string &input);
    static void convertFloat(const std::string &input);
    static void convertDouble(const std::string &input);
};

#endif