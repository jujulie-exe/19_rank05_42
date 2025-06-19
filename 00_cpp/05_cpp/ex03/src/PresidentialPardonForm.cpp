#include "../include/PresidentialPardonForm.hpp"

       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
PresidentialPardonForm::PresidentialPardonForm(const std::string& targetREF)
	: AForm("ShrubberyCreationForm", 25, 5), _target( targetREF )
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
	: AForm(src), _target( src._target)
{
    std::cout << "Copy constructor called" << std::endl;
    //*this = src;
}

       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
void	PresidentialPardonForm::executeAction( void ) const
{
	//Informs that <target> has been pardoned by Zaphod Beeblebrox
	std::cout << this->_target << " has benn pardoned by Zaphod Beeblebrox" << std::endl;
	return ;
}
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        // this->_n = rhs.getValue();
    }
    return *this;
}

       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor called" << std::endl;
    // dtor
}

/* std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &rhs)
{
   o << rhs.getName() << std::endl;
   return o;
} */

