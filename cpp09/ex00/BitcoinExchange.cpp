#include "BitcoinExchange.hpp"

int stringToInt(const std::string& str)
{
    std::istringstream iss(str);
    int value;
    iss >> value;
    return value;
}

float stringToFloat(const std::string& str) {
    std::istringstream iss(str);
    float value;
    iss >> value;
    return value;
}

std::string getDateValue(const std::string& line) {
    std::string date;
    size_t pos = line.find(" | ");
    if (pos != std::string::npos) {
        date = line.substr(0, pos);
    }
    return date;
}

std::string getValue(const std::string& line) {
    std::string value;
    size_t pos = line.find(" | ");
    if (pos != std::string::npos) {
        value = line.substr(pos + 3);
    }
    return value;
}

bool isValidValue(int value)
{
	if (value > 1000)
    {
        std::cerr << "Error: too large number." << std::endl;
        return (false);
    }
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return (false);
    }
    return (true);
}

bool isValidDate(int y, int m, int d)
{
	if (y < 2009 || y > 2022) {
        std::cerr << "Error: Year out of range -> " << y << std::endl;
        return false;
    }
    if (m < 1 || m > 12) {
        std::cerr << "Error: Invalid month -> " << m << std::endl;
        return false;
    }
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        daysInMonth[1] = 29;
    if (d < 1 || d > daysInMonth[m - 1]) {
        std::cerr << "Error: Invalid day -> " << d << std::endl;
        return false;
    }
    return true;
}

bool isValidFormat(const std::string& line)
{
    if (line.find(" | ") == std::string::npos) {
        std::cerr << "Error: Bad input -> " << line << std::endl;
        return false;
    }
    return true;
}

bool isValid(const std::string& line)
{
    if (!isValidFormat(line)) {
        return false;
    }
    std::string date = getDateValue(line);
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        std::cerr << "Error: Invalid date format -> " << date << std::endl;
        return false;
    }
    int year = stringToInt(date.substr(0, 4));
    int month = stringToInt(date.substr(5, 2));
    int day = stringToInt(date.substr(8, 2));
    return (isValidDate(year, month, day));
}



std::map<std::string, float> loadExchangeData(const std::string& filename)
{
    std::map<std::string, float> exchangeData;
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file: " << filename << std::endl;
        return exchangeData;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::string date = getDateValue(line);
        std::string rateStr = getValue(line);
        if (isValid(line)) {
            float rate = stringToFloat(rateStr);
            exchangeData[date] = rate;
        }
    }
    file.close();
    return exchangeData;
}

float findClosestRate(const std::string& date, const std::map<std::string, float>& exchangeData) {
    std::map<std::string, float>::const_iterator it = exchangeData.lower_bound(date);
    if (it != exchangeData.end() && it->first == date) {
        return it->second;
    }
    if (it != exchangeData.begin()) {
        --it;
    }
    return it->second;
}

void printValue(const std::string& date, float num, const std::map<std::string, float>& exchangeData) {
    float exchangeRate = findClosestRate(date, exchangeData);
    if (exchangeRate < 0.0f) {
        std::cerr << "Error: No valid exchange rate for the date -> " << date << std::endl;
        return;
    }
    std::cout << date << " => " << num << " = " << exchangeRate * num << std::endl;
}

void handleInput(const std::string& filename, const std::map<std::string, float>& exchangeData) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file -> " << filename << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::string date = getDateValue(line);
        std::string valueStr = getValue(line);
        float value = stringToFloat(valueStr);
        if (valueStr.empty() || value <= 0.0f) {
            std::cerr << "Error: Invalid value -> " << valueStr << std::endl;
            continue;
        }
        printValue(date, value, exchangeData);
    }
    file.close();
}

	