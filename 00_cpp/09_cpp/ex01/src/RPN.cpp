#include "../include/RPN.hpp"

       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
RPN::RPN(const std::string* args, size_t size)
{
/*	if (size > 10 )
		throw SizeToHight();*/
	if (!miniParser(args, size))
		throw errorParsing();
	executeRPN(args, size);
}

RPN::RPN()
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

RPN::RPN(RPN const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    //*this = src;
}

       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
bool	RPN::miniParser(const std::string* args, const size_t size) const
{
	for (size_t i = 0; i < size; ++i)
	{
		if (args[i].lenght() > 1 || args[i].empty() == true)
			return false;
		size_t found = args[i].find_first_not_of("1234567890-+/*");
		if ( found!=std::string::npos )
			return false;
	}
	return true;
}
static int convertChar(const char c)
{
	std::stringstream ss;
	ss >> c;
	return static_cast<int>ss;
}

bool opAcepetd(const char c)
{
	return (c == '*' || c == '-' || c == '/' || c == '+');
}

void RPN::executeRPN(const std::string* args, const size_t size)
{	
	for (size_t i = 0; i < size; ++i)
	{
		if (std::isdigit(args[i][0]){
				operandi.push(convertChar(args[i][0]);
		}
		if (opAcepetd(args[i][0]) && operandi.size() > 2){
			
		}
		else{
			throw Error();
		}


				
	}
}
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
RPN &RPN::operator=( RPN const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        // this->_n = rhs.getValue();
    }
    return *this;
}

       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
RPN::~RPN()
{
    std::cout << "Destructor called" << std::endl;
    // dtor
}

/* std::ostream &operator<<(std::ostream &o, const RPN &rhs)
{
   o << rhs.getName() << std::endl;
   return o;
} */

