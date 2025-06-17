/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:01:43 by jfranco           #+#    #+#             */
/*   Updated: 2025/06/17 15:16:51 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

/*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/

Bureaucrat::Bureaucrat(const std::string& nameREF, int n)
	: name(nameREF), grade( n )
//(((n < 1) ? 1 : (n > 150 ? 150 : n)))
{
    std::cout << getName() << " " << getGrade() << " Parametre constructor called" << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 0)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat()
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
    std::cout << "Copy constructor called" << std::endl;
	//this->name = src.getName();
	this->grade = src.getGrade();
}

/*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/

std::string Bureaucrat::getName() const
{
	return this->name;
}

int	Bureaucrat::getGrade() const
{
	return this->grade;
}

/*♡♡♡♡♡♡♡♡♡♡♡CLASS♡FT♡♡♡♡♡♡♡♡♡♡♡♡*/

void	Bureaucrat::incrementa( void ) throw(GradeTooHighException)
{
	if (this->grade - 1 < MIN_GRADE)
		throw GradeTooHighException();
	grade--;
}

void	Bureaucrat::decrementa()throw(GradeTooLowException)
{
	if (this->grade + 1 > MAX_GRADE)
		throw GradeTooLowException();
	grade++;
}

/*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
		//this->name = rhs->getName();
		this->grade = rhs.getGrade();
    }
    return *this;
}

/*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
    // dtor
}

/*♡♡♡♡♡♡♡♡♡♡♡EXECPTION♡♡♡♡♡♡♡♡♡♡♡♡♡*/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}


std::ostream &operator<<(std::ostream &obj,  const Bureaucrat &rhs)
{
///<name>, bureaucrat grade <grade>.
	 obj << rhs.getName() << " bureaucrat grade " << rhs.getGrade();
	 return (obj);
}
