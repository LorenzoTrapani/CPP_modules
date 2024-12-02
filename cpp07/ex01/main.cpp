#include "iter.hpp"

template <typename T>
void print(T const &x)
{
    std::cout << x << std::endl;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    std::string stringArray[] = {"one", "two", "three", "four", "five"};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::cout << "IntArray: " << std::endl;
    iter(intArray, 5, print);
    std::cout << "StringArray: " << std::endl;
    iter(stringArray, 5, print);
    std::cout << "DoubleArray: " << std::endl;
    iter(doubleArray, 5, print);
    return 0;
}