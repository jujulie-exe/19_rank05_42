#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

/*♡♡♡♡♡♡♡♡♡♡♡EXECPTION♡♡♡♡♡♡♡♡♡♡♡♡♡*/
const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}
const char* AForm::NoSignedExeption::what() const throw()
{
	return "No signed";
}


/*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
AForm::AForm(const std::string& nameREF, int grd, int exe)
	: name( nameREF ), sign_grade( grd ), execute_grade( exe ), IfSigned( false )
{
    std::cout << getName() << " " << getSignGrade() << " Parametre constructor called" << std::endl;
	if (getSignGrade() > 150 || getExecuteGrade() > 150)
		throw GradeTooLowException();
	else if (getSignGrade() <= 0 || getExecuteGrade() <= 0)
		throw GradeTooHighException();
    // ctor
}

AForm::AForm()
	: name( " " ) , sign_grade( 1 ), execute_grade( 1 ), IfSigned( false )
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

AForm::AForm(AForm const & src)
	: name(src.getName()), sign_grade(src.getSignGrade()), execute_grade(src.getExecuteGrade()), IfSigned(src.getIfSigned())
{
    std::cout << "Copy constructor called" << std::endl;
}

/*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
std::string	AForm::getName() const
{
	return name;
}

int			AForm::getSignGrade() const
{
	return sign_grade;
}

int			AForm::getExecuteGrade() const
{
	return execute_grade;
}

bool		AForm::getIfSigned() const
{
	return IfSigned;
}
 
/*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
void		AForm::beSigned( Bureaucrat &ptr) throw(GradeTooLowException)
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

void		AForm::execute(Bureaucrat const & executor) const throw(GradeTooLowException, NoSignedExeption)
{
	if (this->getIfSigned() != true)
		throw NoSignedExeption();
	if(this->getExecuteGrade() < executor.getGrade())
		throw GradeTooLowException();
	this->executeAction();
}
 
/*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
AForm &AForm::operator=( AForm const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
         this->IfSigned = rhs.getIfSigned();
    return *this;
}

/*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
AForm::~AForm()
{
	std::cout << "Destructor called" << std::endl;
    // dtor
}

std::ostream &operator<<(std::ostream &o, const AForm &rhs)
{
	o << rhs.getName() << " " << rhs.getSignGrade() << " " << rhs.getIfSigned() << " " << rhs.getExecuteGrade() << std::endl;
   return o;
}

