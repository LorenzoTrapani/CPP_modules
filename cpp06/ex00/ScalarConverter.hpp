#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <cctype>
#include <exception>
#include <iomanip>
#include <sstream>


class ScalarConverter
{
public:
	static void convert(std::string input);
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &assign);
	~ScalarConverter();

	static void printSpecial(const std::string &c, const std::string &i, const std::string &f, const std::string &d);
	static void printChar(char c, char type);

	static bool isSpecialValue(const std::string &input);	
	static bool isChar(const std::string &input);
	static bool isInt(const std::string &input);
	static bool isFloat(const std::string &input);
	static bool isDouble(const std::string &input);
	static bool isDisplayable(const std::string &input);

	static void handleSpecialValue(const std::string &input);
    static void convertChar(const std::string &input);
    static void convertInt(const std::string &input);
    static void convertFloat(const std::string &input);
    static void convertDouble(const std::string &input);
};

#endif