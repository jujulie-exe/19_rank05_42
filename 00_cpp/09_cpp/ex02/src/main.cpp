/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:50:44 by jfranco           #+#    #+#             */
/*   Updated: 2025/09/10 15:50:50 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int main()
{
	std::vector<int> test;
	for (size_t i = 10; i != 0 ; --i)
	{
		test.push_back(i);
	}
	for (size_t i = 0; i < test.size(); ++i)
	{
		std::cout << test[i] << " ";
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

	return (0);
}
