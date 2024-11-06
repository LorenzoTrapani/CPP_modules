#include "Bureaucrat.hpp"

int main() 
{
    try {
        Bureaucrat john("John", 50);
        std::cout << john << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat steve("Steve", 0);
		std::cout << steve << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bob("Bob", 200);  
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

	Bureaucrat pier("Pier", 150);
	try {
		std::cout << pier << std::endl;
		pier.decrementGrade();
	} catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

	try {
		pier.incrementGrade();
		std::cout << pier << std::endl;
	} catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
