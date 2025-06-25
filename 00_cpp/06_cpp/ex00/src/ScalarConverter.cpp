#include "../include/ScalarConverter.hpp"

       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
ScalarConverter::ScalarConverter()
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    //*this = src;
}

       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
void	ScalarConverter::convert(const std::string& infoREF)
{
	std::stringstream ss(str);
    double d;
    ss >> d;
    return ss.eof() && !ss.fail();
std::stringstream ss(str);
    char c;
    ss >> c;
    return ss.eof() && !ss.fail() && str.size() == 1; // Deve essere un singolo carattere
	double pi = 3.14159265359;
std::stringstream stream;
stream << std::fixed << std::setprecision(2) << pi;
std::string s = stream.str();

}
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
ScalarConverter &ScalarConverter::operator=( ScalarConverter const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        // this->_n = rhs.getValue();
    }
    return *this;
}

       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructor called" << std::endl;
    // dtor
}

/* std::ostream &operator<<(std::ostream &o, const ScalarConverter &rhs)
{
   o << rhs.getName() << std::endl;
   return o;
} */

