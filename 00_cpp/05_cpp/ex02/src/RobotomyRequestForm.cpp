#include "../include/RobotomyRequestForm.hpp"

static int		lol( void )
{
	static int n = 1;

	return ++n;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& targetREF)
	: AForm("RobotomyRequestForm", 72, 45), _target( targetREF ), _n( 1 )
{
	return ;
}
/*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target( " " ), _n( 1 )
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
	: AForm(src), _target(src._target), _n (src._n)
{
    std::cout << "Copy constructor called" << std::endl;
    //*this = src;
}

/*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
/*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
void	RobotomyRequestForm::executeAction( void ) const
{
	/* Makes some drilling noises, then informs that <target> has been robotomized
	successfully 50% of the time. Otherwise, it informs that the robotomy failed */
	if (lol() % 2)
		std::cout << "Drilling Noise " << this->_target << " has benn robotomized" << std::endl;
	else
		std::cout << "robotomized is falled" << std::endl;
	return ;
}
 
/*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        // this->_n = rhs.getValue();
    }
    return *this;
}

/*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor called" << std::endl;
    // dtor
}

/* std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &rhs)
{
   o << rhs.getName() << std::endl;
   return o;
} */

