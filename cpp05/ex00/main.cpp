#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 0);  // Questo lancerà GradeTooHighException
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Eccezione catturata: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Eccezione catturata: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 200);  // Questo lancerà GradeTooLowException
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Eccezione catturata: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Eccezione catturata: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 50);  // Questo è valido
        std::cout << b3.getName() << " ha un grado di " << b3.getGrade() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Eccezione catturata: " << e.what() << std::endl;
    }

    return 0;
}
