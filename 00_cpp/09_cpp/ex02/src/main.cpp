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
#include <algorithm>

int main()
{
	std::vector<int> test;
	for (size_t i = 15; i != 0 ; --i)
	{
		test.push_back(rand() % 1000 + 1);
	}
	for (size_t i = 0; i < test.size(); ++i)
	{
		std::cout << test[i] << " ";
	}
	if (std::is_sorted(test.begin(), test.end()) == true)
	{
		std::cout << "is sorted \n ";
	}
	else
	{
		std::cout << "is not sorted \n ";
	}
	PmergeMe instance;
	clock_t init = clock();
	instance.FordJohnsonVector(test, 1);
	clock_t end = clock();
	std::cout << "Time to process a range of"  << ((float)(end - init)) *1000 / (CLOCKS_PER_SEC) << " whit: std::list \n";
	std::cout << "After: ";
	for (size_t i = 0; i < test.size(); ++i)
	{
		std::cout << test[i] << " ";
	}
	std::cout << "\n";
	std::cout << instance.getNumberCmp() << "\n";
	if (std::is_sorted(test.begin(), test.end()) == true)
	{
		std::cout << "is sorted \n ";
	}
	else
	{
		std::cout << "is not sorted \n ";

	}

	return (0);
}
