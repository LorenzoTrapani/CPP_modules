#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
#include <string>

class Brain
{
	public:
	Brain();
	Brain(const Brain &copy);
	~Brain();
	Brain &operator=(const Brain &src);
	
	std::string ideas[100];
};

#endif