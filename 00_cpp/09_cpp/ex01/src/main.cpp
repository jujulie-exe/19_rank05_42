/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:42:57 by jfranco           #+#    #+#             */
/*   Updated: 2025/08/27 18:18:06 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"
static size_t ftTokeCount(const std::string& strREF)
{
	size_t i = 0;
	std::stringstream ss(strREF);
	std::string token;
	ss >> std::skipws;
	while (ss >> token)
	{
		i++;
	}
	return i;
}


int main(int argc, char **argv)
{
	if (argc == 1)
		return 0;
	std::string* prmtrs;
	size_t	size;
	if (argc > 2)
	{
		prmtrs = new std::string[argc - 1];
		char **Cpy = argv + 1;
		size = argc - 1;
		for (size_t i = 0; i < argc - 1; ++i)
		{
			prmtrs[i] = std::string(Cpy[i]);
		}
	}
	else
	{
		size_t i = 0;
		size_t y = 0;
		std::string Cpy = std::string(argv[1]);
		prmtrs = new std::string[ftTokeCount(Cpy)];
		size = ftTokeCount(Cpy);
		std::stringstream ss(Cpy);
		ss >> std::skipws;
		while (ss >> prmtrs[i])
		{
			i++;
		}
	}
	try 
	{
		RPN instance(prmtrs, size);
		delete[] prmtrs;
	}
	catch(std::exception & e)
	{
		std::cout << e.what();
		delete[] prmtrs;
	}
	return 1;
}
