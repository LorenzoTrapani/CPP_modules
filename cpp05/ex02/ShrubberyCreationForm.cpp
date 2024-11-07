#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSign())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file");
	file << "	            /\\      " << std::endl;
	file << "               /\\*\\     " << std::endl;
	file << "              /\\O\\*\\    " << std::endl;
	file << "             /*/\\/\\/\\   " << std::endl;
	file << "            /\\O\\/\\*\\/\\  " << std::endl;
	file << "           /\\*\\/\\*\\O\\/\\ " << std::endl;
	file << "          /\\O\\/\\/*/\\/\\O\\ " << std::endl;
	file << "         /\\O\\/\\/*/\\/O/\\/\\ " << std::endl;
	file << "        /\\O\\/\\/*/\\/O/\\/*/\\ " << std::endl;
	file << "       /\\O\\/\\/*/\\/O/\\/*/\\O\\ " << std::endl;
	file << "      /\\O\\/\\/*/\\/O/\\/*/\\/O/\\ " << std::endl;
	file << "     /\\O\\/\\/*/\\/O//**\\O/\\/*/\\ " << std::endl;
	file << "    /\\O\\/\\/*/\\/O/\\/\\/\\/*/\\/O/\\  " << std::endl;
	file << "            ||||||||      " << std::endl;
	file << "            ||0||0||      " << std::endl;
	file << "            ||||||||      " << std::endl;
	file << "              ||||      " << std::endl;
	file << "          //||||||||\\\\     " << std::endl;
	file << "         // |||||||| \\\\    " << std::endl;
	file << "        //  ||||||||  \\\\   " << std::endl;
	file << "       //   ||||||||   \\\\  " << std::endl;
	file << "      //    ||||||||    \\\\ " << std::endl;
	file << "     //     ||||||||     \\\\ " << std::endl;
	file << "    //      ||||||||      \\\\" << std::endl;
	file << "   //       ||||||||       \\\\" << std::endl;
	file << "  //         ||||||         \\\\" << std::endl;
	file << " //           ||||           \\\\" << std::endl;
	file << " //           ||||           \\\\" << std::endl;
	file << " ||           ||||           ||" << std::endl;
	file << " ||           ||||           ||" << std::endl;
	file << "          \\==========/      " << std::endl;
	file << "           \\********/      " << std::endl;
	file << "            \\******/      " << std::endl;
	file << "             \\****/      " << std::endl;	
	file << "              \\__/      " << std::endl;
	file << std::endl;
	file.close();
}
