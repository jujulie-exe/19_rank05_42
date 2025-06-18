/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:20:05 by jfranco           #+#    #+#             */
/*   Updated: 2025/06/18 19:28:26 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int	main()
{
	size_t	i = 0;
	size_t y = 0;
	Bureaucrat* instance2 = NULL;
	try
	{
		instance2 = new Bureaucrat("Mario", 10);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: standard " << e.what() << std::endl;
	}


	try
	{
		Bureaucrat instance1("Charlie", 250);
		std::cout << instance1 << std::endl;
		while(i < 200)
		{
			try
			{
				instance1.incrementa();
			}
			catch(const Bureaucrat::GradeTooHighException& e) 
			{
				std::cout << "Exception: class " << e.what() << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "Exception: standard" << e.what() << std::endl;
			}
			catch(...)
			{
				std::cout << "Altro " << std::endl;
			}
			i++;
		}
	std::cout << instance1 << std::endl;
	}
	catch(const std::exception& e)
    {
        std::cout << "Exception: standard " << e.what() << std::endl;
    }


	if (instance2)
	{
		std::cout << "Try stamp mario " << *instance2 << std::endl;
			while(y <= 148)
			{
				try
				{
					instance2->decrementa();
				}
				catch(const Bureaucrat::GradeTooHighException& e) 
				{
					std::cout << "Exception: class " << e.what() << std::endl;
				}
				catch(const Bureaucrat::GradeTooLowException& e) 
				{
					std::cout << "Exception: class " << e.what() << std::endl;
				}
				catch(const std::exception& e)
				{
					std::cout << "Exception: standard" << e.what() << std::endl;
				}
				catch(...)
				{
					std::cout << "Altro " << std::endl;
				}
				y++;
			}
		delete instance2;
	}
	ShrubberyCreationForm n1("Mamma");
	Bureaucrat n2("Giorgio", 1);
	try
	{
		n2.signForm(&n1);
		n1.execute(n2);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: standard " << e.what() << std::endl;
	}

}
