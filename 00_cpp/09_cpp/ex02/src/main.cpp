/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:50:44 by jfranco           #+#    #+#             */
/*   Updated: 2025/09/11 18:08:01 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"
#include <stdlib.h>
#include <sstream>
static int my_atoi_stream(const std::string &s)
{
    std::istringstream iss(s);
    int value = 0;
    iss >> value;
    return value;
}

template <typename T>
static void printe(const T& container) {
    size_t m;
    if (container.size() > 21) {
        m = 21;
    } else {
        m = container.size();
    }
    for (size_t i = 0; i < m; ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << "\n";
}

template <typename T>
static bool is_sorted(const T& container) {
    for (size_t i = 1; i < container.size(); ++i) {
        if (container[i] < container[i - 1]) {
            return false;
        }
    }
    return true;
}


static bool miniParser(char **argc, size_t size, std::vector<int> &vec, std::deque<int> &dequ, bool flags)
{
	std::string cpy;
	if (flags == true)
	{
	    for (size_t i = 0; i < size; ++i) {
	        cpy += argc[i];
	        cpy += " ";
	    }
	    std::size_t found = cpy.find_first_not_of("1234567890 ");
	    if (found != std::string::npos)
	    {
	        std::cout << "Il primo carattere non numerico è '" << cpy[found]
	                  << "' alla posizione " << found << '\n';
	        return false;
	    }
	}
	else
	{
		cpy = std::string(argc[0]);
		std::size_t found = cpy.find_first_not_of("1234567890 ");
		(void)size;
		if (found!=std::string::npos)
		{
			std::cout << "The first alphabetic character is " << cpy[found];
			std::cout << " at position " << found << '\n';
			return false;
		}
	}
	std::stringstream ss(cpy);
	std::string token;
	while (ss >> token)
	{	
		vec.push_back(my_atoi_stream(token)); // fix: atoi expects const char*
        dequ.push_back(my_atoi_stream(token)); // assuming you also want to fill deque
	}


	// check double
	for (size_t i = 0; i < vec.size(); ++i)
	{
		for (size_t y = i + 1; y < vec.size(); ++y )
		{
			if (vec[i] == vec[y])
			{
				std::cout << "nbr is not unique\n";
				return false;
			}
		}
	}
	return true;
	
}
int main(int argc, char **argv)
{
	bool miniPars = true;
	if (argc > 2)
	{
		miniPars = true;
	}
	else if (argc == 2)
	{
		miniPars = false;
	}
	else if (argc <= 1)
	{
		return 0;
	}
	std::vector<int> vec;
	std::deque<int> deque;
	if (miniParser(argv + 1, argc - 1, vec, deque, miniPars) == false)
		return 1;
	PmergeMe instance;
	clock_t init = clock();
	instance.FordJohnsonVector(vec, 1);
	clock_t end = clock();
	std::cout << "Time to process a range of"  << ((float)(end - init)) *1000 / (CLOCKS_PER_SEC) << " whit: std::vector \n";
	std::cout << "After: ";
	printe(vec);
	init = clock();
	instance.FordJohnsonVector(deque, 1);
	end = clock();
	std::cout << "Time to process a range of"  << ((float)(end - init)) *1000 / (CLOCKS_PER_SEC) << " whit: std::vector \n";
	std::cout << "After: ";
	printe(deque);
	if (!(is_sorted(vec) == false || is_sorted(deque)))
	{
		std::cout << "is NOT SORTED!!" << "\n";
	}
	std::cout << "\n";

	return (0);
}
