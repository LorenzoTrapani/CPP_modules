#include "Base.hpp"

Base *generate() {
	int random = rand() % 3;
	if (random == 0) {
		std::cout << "Generated A" << std::endl;
		return new A;
	}
	else if (random == 1) {
		std::cout << "Generated B" << std::endl;
		return new B;
	}
	else {
		std::cout << "Generated C" << std::endl;
		return new C;
	}
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "Pointer is of type A" << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "Pointer is of type B" << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << "Pointer is of type C" << std::endl;
	}
	else {
		std::cerr << "Unknown type" << std::endl;
	}
}

void identify(Base &p) {
	int unknown = 0;
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (const std::exception& e) {
		unknown++;
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (const std::exception& e) {
		unknown++;
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (const std::exception& e) {
		unknown++;
	}
	if (unknown == 3)
		std::cerr << "Unknown type" << std::endl;
}