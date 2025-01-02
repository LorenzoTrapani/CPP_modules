#include "BitcoinExchange.hpp"

std::string getDateValue(std::string line)
{
	std::string date;
	for (int i = 0; line[i]; i++) {
		if (line[i] != ' ')
			date += line[i];
		if (line[i] == ' ' && line[i + 1] == '|')
			break;
	}
	return (date);
}

std::string getValue(std::string line)
{
	std::string value;
	unsigned long int pos = 0;
	for (int i = 0; line[i]; i++) {
		if (line[i] == ' ' && line[i + 1] == '|') {
			pos = i + 2;
			break;
		}
	}
	while (pos < line.length())
	{
		value += line[pos];
		pos++;
	}
	return (value);
}

bool isValidValue(int value)
{
	if (value == -2147483648 || value > 1000)
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

bool isValid(std::string line)
{
	if(strstr(line.c_str(), ",") == NULL)
	{
		return false;
	}
	int m = atoi(line.c_str() + 5);
	int d = atoi(line.c_str() + 8);
	int y = atoi(line.c_str() + 0);
	if (!isValidDate(y, m, d))
		return false;
	return true;
}

float getExchangeRate(std::string date)
{
	std::fstream db;
	db.open("data.csv");
	std::string line;
	std::string save;
	std::getline(db, line);
	while (std::getline(db, line))
	{
		if (getDateValue(line) == date)
		{
			save = line;
			break ;
		}
		else if (getDateValue(line) >= date)
			break ;
		save = line;
	}
	db.close();
	return(atof(getValue(save).c_str()));
}

void printValue(std::string date, float num, std::string line)
{
	if (!isValid(line))
	{
		std::cerr << "Error: Bad input" << line << std::endl;
		return;
	}
	float exchangeRate = getExchangeRate(date);
	long int value = num;
	if (exchangeRate == -1 || isValidValue(value) == false)
		return;
	std::cout << date << "=>" << value << "=" << exchangeRate << std::endl;
}

void handleInput(std::string filename)
{
	std::map<std::string, float> data;
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Unable to open file");
	std::string line;
	std::string date;
	float value;
	while (std::getline(file, line)) {
		date = getDateValue(line);
		value = atof(getValue(line).c_str());
		data[date] = value;
		printValue(date, data[date], line);
	}
	file.close();
}
	