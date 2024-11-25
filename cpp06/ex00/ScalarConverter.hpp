#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>

class ScalarConverter
{
public:
	static void convert(std::string input);
private:
	ScalarConverter();
	~ScalarConverter();

	class ImpossibleConversionException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class NonDisplayableException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class InvalidInputException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

#endif