#include "BitcoinExchange.hpp"

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
	handleInput(argv[1], exchangeData);
	return 0;
}