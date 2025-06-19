/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:20:05 by jfranco           #+#    #+#             */
/*   Updated: 2025/06/19 20:06:29 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/Intern.hpp"

int	main()
{
	AForm					*FormN1;
	AForm					*FormN2;
	AForm					*FormN3;
	Bureaucrat				*BuroN1;	
	Bureaucrat				*BuroN2;	
	Bureaucrat				*BuroN3;	
	try
	{
		FormN1 = new ShrubberyCreationForm("CULO");
		FormN2 = new PresidentialPardonForm("PARK");
		FormN3 = new RobotomyRequestForm("WOOD");
	}
	catch(const std::exception& e)
	{
		std::cout << "ERRORE IN:" << e.what() << std::endl;
	}

	try
	{
		BuroN1 = new Bureaucrat("Mario", 150);
		BuroN2 = new Bureaucrat("Giovanni", 1);
		BuroN3 = new Bureaucrat("Luca", 150);
	}
	catch(const std::exception& e)
	{
		std::cout << "ERRORE IN:" << e.what() << std::endl;
	}
	BuroN1->signForm(FormN1);
	BuroN2->signForm(FormN1);
	BuroN3->signForm(FormN1);
	BuroN1->signForm(FormN2);
	BuroN1->signForm(FormN2);
	BuroN2->signForm(FormN2);
	BuroN3->signForm(FormN3);
	BuroN2->signForm(FormN3);
	BuroN3->signForm(FormN3);
	BuroN1->executeForm(*FormN1);
	BuroN2->executeForm(*FormN1);
	BuroN3->executeForm(*FormN1);
	BuroN1->executeForm(*FormN2);
	BuroN1->executeForm(*FormN2);
	BuroN2->executeForm(*FormN2);
	BuroN3->executeForm(*FormN3);
	BuroN2->executeForm(*FormN3);
	BuroN3->executeForm(*FormN3);
	BuroN2->executeForm(*FormN3);
	BuroN2->executeForm(*FormN3);
	BuroN2->executeForm(*FormN3);
	BuroN2->executeForm(*FormN3);
	BuroN2->executeForm(*FormN3);
	BuroN2->executeForm(*FormN3);
	BuroN2->executeForm(*FormN3);
	BuroN2->executeForm(*FormN3);
Intern someRandomIntern;
AForm* rrf;
rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
if (rrf)
{
	BuroN2->executeForm(*rrf);
	delete rrf;
}

	delete FormN1;
	delete FormN2;
	delete FormN3;
	delete BuroN1;
	delete BuroN2;
	delete BuroN3;
return (0);
}
