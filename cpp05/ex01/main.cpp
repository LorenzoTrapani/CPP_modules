#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat steve("Steve", 2);
		Bureaucrat george("George", 150);
		Form war("War agreement", 1, 1);
		Form peace("Peace agreement", 150, 150);
		std::cout << steve << std::endl;
		std::cout << george << std::endl;
		std::cout << war << std::endl;
		std::cout << peace << std::endl;

		steve.signForm(war);
		steve.incrementGrade();
		steve.signForm(war);
	
		george.signForm(war);
		george.signForm(peace);

		std::cout << war << std::endl;
		std::cout << peace << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}