/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:50:44 by jfranco           #+#    #+#             */
/*   Updated: 2025/08/29 19:00:27 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int main()
{
	std::string args[6]= {"2", "6", "9", "15", "4", "1"};
	size_t size = 6;
	PmergeMe instance(args, size);
	instance.printTreeList();
	instance.pairList(0, instance.getStart());
	instance.printTreeList();
	return (0);
}
