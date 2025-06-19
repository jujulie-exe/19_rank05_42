#include "../include/Intern.hpp"

       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
Intern::Intern()
{
    std::cout << "Default constructor called" << std::endl;
	_FunPTR[0] = &Intern::CreateShrubberyCreationForm;
	_FunPTR[1] = &Intern::CreatePresidentialPardonForm;
	_FunPTR[2] = &Intern::CreateRobotomyRequestForm;
    // ctor
}

Intern::Intern(Intern const & src)
{
    std::cout << "Copy constructor called" << std::endl;
	(void)src;
	_FunPTR[0] = &Intern::CreateShrubberyCreationForm;
	_FunPTR[1] = &Intern::CreatePresidentialPardonForm;
	_FunPTR[2] = &Intern::CreateRobotomyRequestForm;
    //*this = src;
}

       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
	size_t	i = 0;	
	std::string info[] = {"ShrubberyCreationForm", "PresidentialPardonForm", "RobotomyRequestForm",  ""}; 
	while (!info[i].empty())
	{
		if (info[i] == name)
			return (this->*_FunPTR[i])(target);
		i++;
	}
	std::cerr << "inserimento di un form sbagliato" << std::endl;
	return NULL;
}

AForm* Intern::CreateRobotomyRequestForm(const std::string &REF) const
{
	return new RobotomyRequestForm(REF);
}

AForm* Intern::CreatePresidentialPardonForm(const std::string &REF) const
{
	return new PresidentialPardonForm(REF);
}

AForm* Intern::CreateShrubberyCreationForm(const std::string &REF) const
{
	return new ShrubberyCreationForm(REF);
}
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
Intern &Intern::operator=( Intern const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
	(void)rhs;
    return *this;
}

       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
Intern::~Intern()
{
    std::cout << "Destructor called" << std::endl;
    // dtor
}

/* std::ostream &operator<<(std::ostream &o, const Intern &rhs)
{
   o << rhs.getName() << std::endl;
   return o;
} */

