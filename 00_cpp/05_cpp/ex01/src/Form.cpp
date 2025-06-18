#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

/*♡♡♡♡♡♡♡♡♡♡♡EXECPTION♡♡♡♡♡♡♡♡♡♡♡♡♡*/
const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

/*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
Form::Form(const std::string& nameREF, int grd, int exe)
	: name( nameREF ), sign_grade( grd ), execute_grade( exe ), IfSigned( false )
{
    std::cout << getName() << " " << getSignGrade() << " Parametre constructor called" << std::endl;
	if (getSignGrade() > 150 || getExecuteGrade() > 150)
		throw GradeTooLowException();
	else if (getSignGrade() <= 0 || getExecuteGrade() <= 0)
		throw GradeTooHighException();
    // ctor
}

Form::Form()
	: name( " " ) , sign_grade( 1 ), execute_grade( 1 ), IfSigned( false )
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

Form::Form(Form const & src)
	: name(src.getName()), sign_grade(src.getSignGrade()), execute_grade(src.getExecuteGrade()), IfSigned(src.getIfSigned())
{
    std::cout << "Copy constructor called" << std::endl;
}

/*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
std::string	Form::getName() const
{
	return name;
}

int			Form::getSignGrade() const
{
	return sign_grade;
}

int			Form::getExecuteGrade() const
{
	return execute_grade;
}

bool		Form::getIfSigned() const
{
	return IfSigned;
}
 
/*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
void		Form::beSigned( Bureaucrat &ptr) throw(GradeTooLowException)
{
	if (this->getIfSigned() == false)
	{
		if (ptr.getGrade() <= this->getSignGrade())
			this->IfSigned = true;
		else
			throw GradeTooLowException();
	}
	return;
}
 
/*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
Form &Form::operator=( Form const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
         this->IfSigned = rhs.getIfSigned();
    return *this;
}

/*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
Form::~Form()
{
	std::cout << "Destructor called" << std::endl;
    // dtor
}

std::ostream &operator<<(std::ostream &o, const Form &rhs)
{
	o << rhs.getName() << " " << rhs.getSignGrade() << " " << rhs.getIfSigned() << " " << rhs.getExecuteGrade() << std::endl;
   return o;
}

