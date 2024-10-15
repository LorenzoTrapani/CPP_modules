/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:37:12 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/15 14:33:02 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string filename, std::string s1, std::string s2) : _filename(filename), _s1(s1), _s2(s2) {}

Replace::~Replace() {}

void	Replace::setReplace()
{
	std::ifstream	inFile(_filename.c_str());
	std::ofstream	outFile((_filename + ".replace").c_str());
	std::string		line;

	if (!inFile)
	{
		std::cout << "Error: could not open file" << std::endl;
		return ;
	}
	if (!outFile)
	{
		std::cout << "Error: could not create file" << std::endl;
		return ;
	}
	while (std::getline(inFile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(_s1)) != std::string::npos)
		{
			line.erase(pos, _s1.length());
			line.insert(pos, _s2);
			pos += _s2.length();
		}
		outFile << line << std::endl;
	}
	inFile.close();
	outFile.close();
}

