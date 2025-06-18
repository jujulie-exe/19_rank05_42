/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:01:43 by jfranco           #+#    #+#             */
/*   Updated: 2025/06/18 18:58:08 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

/*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/

Bureaucrat::Bureaucrat(const std::string& nameREF, int n)
	: name(nameREF), grade( n )
//(((n < 1) ? 1 : (n > 150 ? 150 : n)))
{
    std::cout << getName() << " " << getGrade() << " Parametre constructor called" << std::endl;
	if (grade > MAX_GRADE)
		throw GradeTooLowException();
	else if (grade < MIN_GRADE)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat()
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
	: name(src.getName()), grade(src.getGrade())
{
    std::cout << "Copy constructor called" << std::endl;
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

void	Bureaucrat::signForm( AForm* src)
{
	if (src != NULL)
	{
		if (src->getIfSigned() == true)
		{
			std::cout << this->getName() << " couldn't signed " << src->getName() << " because " << " alredy signed " << std::endl; 
			return ;
		}
		try
		{
			src->beSigned(*this);
		}
		catch(const AForm::GradeTooLowException& e) 
		{
			std::cout << this->getName() << " couldn't signed " << src->getName() << " because " << " GradeTooLow " << std::endl; 
		}
		if (src->getIfSigned())
		{
			std::cout << this->getName() << " signed " << src->getName() << std::endl; 
		}
	}
	return ;
}
	/*<bureaucrat> signed <form>
	 *<bureaucrat> couldn’t sign <form> because <reason>.
*/

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


std::ostream &operator<<(std::ostream &o,  const Bureaucrat &rhs)
{
///<name>, bureaucrat grade <grade>.
	 o << rhs.getName() << " bureaucrat grade " << rhs.getGrade();
	 return (o);
}
