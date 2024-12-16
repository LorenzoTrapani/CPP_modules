#include <iostream>
#include <ctime>
#include <cstdlib>
#include "array.hpp"

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Usage: ./Array <MAX_VAL>" << std::endl;
        return 1;
    }

    int MAX_VAL = std::atoi(argv[1]);
    if (MAX_VAL <= 0) {
        std::cerr << "Error: MAX_VAL must be a positive integer." << std::endl;
        return 1;
    }

    Array<int> numbers(MAX_VAL);
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand() % 100;
    }

    std::cout << "Generated Array:" << std::endl;
    for (int i = 0; i < MAX_VAL; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}