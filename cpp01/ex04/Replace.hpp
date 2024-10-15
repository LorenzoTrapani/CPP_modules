/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:32:09 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/15 14:30:13 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <string>

class Replace
{
public:
	Replace(std::string filename, std::string s1, std::string s2);
	~Replace();
	void	setReplace();
private:
	std::string	_filename;
	std::string	_s1;
	std::string	_s2;
};

#endif