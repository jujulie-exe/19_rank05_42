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

int main(int argc, char **argv)
{
	std::string* prmtrs;
	size_t	size;
	if (argc > 2)
	{
		prmtrs = new std::string[argc - 1];
		char **Cpy = argv + 1;
		size = argc - 1;
		for (int i = 0; i < argc - 1; ++i)
		{
			prmtrs[i] = std::string(Cpy[i]);
		}
	}
	else
		return (0);
	PmergeMe instance(prmtrs, size);
	std::cout << "Before: ";
	instance.printTreeList();
	clock_t init = clock();
	instance.pairList(0, instance.getStart());
	for (size_t i = 0; instance.getSize() != 1; ++i){
		instance.executeSortList();
	}
	clock_t end = clock();
	std::cout << "Time to process a range of"  << ((float)(end - init)) *1000 / (CLOCKS_PER_SEC) << " whit: std::list \n";
	std::cout << "After: ";
	instance.printTreeList();
	init = clock();
	instance.pairDeque(0, instance.getStartDeque());
	for (size_t i =0; instance.getSizeDeque() != 1; ++i)
	{
		instance.executeSortDeque();
	}
	end = clock();
	std::cout << "Time to process a range of"  << ((float)(end - init)) *1000 / (CLOCKS_PER_SEC) << " whit: std::dque \n";
	std::cout << "After: ";
	instance.printTreeDeque();
	delete[] prmtrs;

	return (0);
}
