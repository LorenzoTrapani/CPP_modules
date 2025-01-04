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

std::string getDateValue(const std::string& line, const std::string &type) {
    std::string date;
	size_t pos = line.find(type);
    if (pos != std::string::npos)
        date = line.substr(0, pos);
    return date;
}

std::string getValue(const std::string& line, const std::string &type) {
    std::string value;
    size_t pos = line.find(type);
    if (pos != std::string::npos)
        value = line.substr(pos + type.length());
    return value;
}

bool isValidValue(float value)
{
	if (value > 1000.0f) {
        std::cerr << "Error: too large number: " << value << std::endl;
        return (false);
    }
    if (value < 0.0f) {
        std::cerr << "Error: not a positive number: " << value << std::endl;
        return (false);
    }
    return (true);
}

bool isValidDate(int y, int m, int d)
{
    if (m < 1 || m > 12) 
        return false;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        daysInMonth[1] = 29;
    if (d < 1 || d > daysInMonth[m - 1])
        return false;
    return true;
}

bool isValidFormat(const std::string& line, const std::string &type)
{
	if (line.find(type) == std::string::npos) {
		std::cerr << "Error: Bad format input -> " << line << std::endl;
		return false;
	}
    return true;
}

bool isValid(const std::string& line, const std::string &date, const std::string &type)
{
    if (!isValidFormat(line, type))
        return false;
    int year = stringToInt(date.substr(0, 4));
    int month = stringToInt(date.substr(5, 2));
    int day = stringToInt(date.substr(8, 2));
	if (!isValidDate(year, month, day)) {
		std::cerr << "Error: Invalid date -> " << date << std::endl;
		return false;
	}
    return true;
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
        std::string date = getDateValue(line, ",");
        std::string rateStr = getValue(line, ",");
        if (isValid(line, date, ",")) {
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
    std::cout << date << "[" << exchangeRate << "]" << " => " << num << " = " << exchangeRate * num << std::endl;
}

void handleInput(const std::string& filename, const std::map<std::string, float>& exchangeData) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file -> " << filename << std::endl;
        return;
    }
    std::string line;
	std::getline(file, line);
	int i = 2;
    while (std::getline(file, line)) {
        std::string date = getDateValue(line, " | ");
        std::string valueStr = getValue(line, " | ");
        float value = stringToFloat(valueStr);
		std::cout << "[" << i++ << "]" << "\t";
        if (!isValid(line, date, " | ") || !isValidValue(value)) 
            continue;
        printValue(date, value, exchangeData);
    }
    file.close();
}

	