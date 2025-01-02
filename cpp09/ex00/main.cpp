#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Example: ./btc [input_file]" << std::endl;
		return 1;
	}
	handleInput(argv[1]);
	return 0;
}