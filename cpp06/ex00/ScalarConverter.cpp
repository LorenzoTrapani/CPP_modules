#include "ScalarConverter.hpp"

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

const char *ScalarConverter::ImpossibleConversionException::what() const throw()
{
    return ("impossible");
}

const char *ScalarConverter::NonDisplayableException::what() const throw()
{
    return ("Non displayable");
}

const char *ScalarConverter::InvalidInputException::what() const throw()
{
    return ("Invalid input");
}

bool ScalarConverter::isChar(const std::string &input)
{
    if (input.length() == 1 && !isdigit(input[0]))
        return (true);
    return (false);
}

bool ScalarConverter::isInt(const std::string &input)
{
    char *end;

    strtol(input.c_str(), &end, 10);
    if (*end)
        return (false);
    return (true);
}

void ScalarConverter::convertChar(const std::string &input)
{
    std::string str = input;
    std::cout << "charconvert" << std::endl;
}

void ScalarConverter::convertInt(const std::string &input)
{
    int i = strtol(input.c_str(), NULL, 10);
    char c = static_cast<char>(i);
    double d = static_cast<double>(i);
    float f = static_cast<float>(i);

    if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
        throw ScalarConverter::ImpossibleConversionException();
    else if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        throw ScalarConverter::NonDisplayableException();
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << ".0f" << std::endl;
    std::cout << "double: " << d << ".0" << std::endl;
}

void ScalarConverter::convert(std::string input)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (!isprint(input[i]))
        {
            throw ScalarConverter::NonDisplayableException();
            return;
        }
    }
    if (isChar(input))
        convertChar(input);
    else if (isInt(input))
        convertInt(input);
    /*else if (isFloat(input))
        convertFloat(input);
    else if (isDouble(input))
        convertDouble(input);*/
    else
        throw ScalarConverter::InvalidInputException();
}