/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:59:09 by jfranco           #+#    #+#             */
/*   Updated: 2025/08/06 16:01:56 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		BitcoinExchange First;
		if (First.OpenAndParserDB("cpp_09/data.csv") == 0)
		{
			std::cout << "Error parser in DB\n";
			return (1);
		}
		if (First.OpenAndParserINP(std::string(argv[1])) == 0)
		{
			return (1);
		}
	}
	return (0);
}
