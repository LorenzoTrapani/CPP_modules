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

bool ScalarConverter::isSpecialValue(const std::string &input)
{
    return (input == "+inf" || input == "-inf" || input == "nan" ||
            input == "+inff" || input == "-inff" || input == "nanf");
}

bool ScalarConverter::isChar(const std::string &input)
{
    return (input.length() == 1 && !isdigit(input[0]));
}

bool ScalarConverter::isInt(const std::string &input)
{
    char *end;
    strtol(input.c_str(), &end, 10);
    return (*end == '\0');
}

bool ScalarConverter::isFloat(const std::string &input)
{
    char *end;
    strtof(input.c_str(), &end);
    if (*end == 'f')
        end++;
    return (*end == '\0');
}

bool ScalarConverter::isDouble(const std::string &input)
{
    char *end;
    strtod(input.c_str(), &end);
    return (*end == '\0');
}

void ScalarConverter::convertChar(const std::string &input)
{
    char c = input[0];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertInt(const std::string &input)
{
    int i = strtol(input.c_str(), NULL, 10);
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << ".0f" << std::endl;
    std::cout << "double: " << d << ".0" << std::endl;
}

void ScalarConverter::convertFloat(const std::string &input)
{
    float f = strtof(input.c_str(), NULL);
    char c = static_cast<char>(f);
    int i = static_cast<int>(f);
    double d = static_cast<double>(f);

    if (std::isnan(f) || std::isinf(f))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
            std::cout << "char: impossible" << std::endl;
        else if (isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << i << std::endl;
    }

    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertDouble(const std::string &input)
{
    double d = strtod(input.c_str(), NULL);
    char c = static_cast<char>(d);
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);

    if (std::isnan(d) || std::isinf(d))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
            std::cout << "char: impossible" << std::endl;
        else if (isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << i << std::endl;
    }

    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(std::string input)
{
    if (isSpecialValue(input))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (input[input.length() - 1] == 'f')
            std::cout << "float: " << input << std::endl;
        else
            std::cout << "float: " << input << "f" << std::endl;
        std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
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
