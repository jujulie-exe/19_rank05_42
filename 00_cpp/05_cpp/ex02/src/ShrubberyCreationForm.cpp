#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>

/*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& targetREF)
	: AForm("ShrubberyCreationForm", 145, 137), _target( targetREF )
{
    // ctor
}
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
	: AForm(src), _target( src._target )
{
    std::cout << "Copy constructor called" << std::endl;
    //*this = src;
}

/*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
/*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
void	ShrubberyCreationForm::executeAction( void ) const
{
	std::string filename = this->_target + std::string("_shrubbery");
	std::ofstream OutFile(filename.c_str());	
	if(!OutFile)
	{
		std::cerr << "can´t open file: " << filename << std::endl;
		return ;
	}
	OutFile << "   /* \n";
	OutFile << "  /*** \n";
	OutFile << " /***** \n";
	OutFile << "/******* \n";
	OutFile << "  |** \n";
	OutFile << "  |** \n";
	OutFile.close();
}
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        // this->_n = rhs.getValue();
    }
    return *this;
}

       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor called" << std::endl;
    // dtor
}

/* std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &rhs)
{
   o << rhs.getName() << std::endl;
   return o;
} */

