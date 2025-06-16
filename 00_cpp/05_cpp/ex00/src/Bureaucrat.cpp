#include "../include/Bureaucrat.hpp"


Bureaucrat::Bureaucrat()
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
    std::cout << "Copy constructor called" << std::endl;
	this->name = src->getName();
	this->grade = src->getGrade();
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
		this->name = src->getName();
		this->grade = src->getGrade();
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
    // dtor
}

