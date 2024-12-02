#include "iter.hpp"

void print_int(int x) {
    std::cout << x << std::endl;
}

void print_double(double x) {
    std::cout << x << std::endl;
}

void increment_int(int &x) {
    x++;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::cout << "doubleArray:" << std::endl;
    iter(doubleArray, 5, print_double);
    std::cout << "intArray:" << std::endl;
    iter(intArray, 5, print_int);
    iter(intArray, 5, increment_int);
    std::cout << "intArray after increment:" << std::endl;
    iter(intArray, 5, print_int);
    return 0;
}
