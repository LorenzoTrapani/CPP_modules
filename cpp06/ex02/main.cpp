#include "Base.hpp"

int main() {
    std::srand(static_cast<unsigned>(std::time(0)));

    Base* obj = generate();

    std::cout << "Identify using pointer: ";
    identify(obj);

    std::cout << "Identify using reference: ";
    identify(*obj);

    delete obj;

    return 0;
}
