/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:50:44 by jfranco           #+#    #+#             */
/*   Updated: 2025/08/31 18:47:29 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int main()
{
	std::string args[10]= {"2", "6", "15", "9", "4", "1", "7", "5", "3", "100"};
	size_t size = 10;
	PmergeMe instance(args, size);
	instance.printTreeList();
	instance.pairList(0, instance.getStart());
	instance.printTreeList();

	return (0);
}
