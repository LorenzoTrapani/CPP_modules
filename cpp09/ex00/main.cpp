#include "BitcoinExchange.hpp"

void printMap(const std::map<std::string, float>& exchangeData) {
	for (std::map<std::string, float>::const_iterator it = exchangeData.begin(); it != exchangeData.end(); ++it) {
		std::cout << it->first << " => " << it->second << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Example: ./btc [input_file]" << std::endl;
		return 1;
	}
	std::map<std::string, float> exchangeData = loadExchangeData("data.csv");
	if (exchangeData.empty()) {
		std::cerr << "Error: Unable to load exchange data" << std::endl;
		return 1;
	}
	// printMap(exchangeData);
	// (void)argv;
	handleInput(argv[1], exchangeData);
	return 0;
}