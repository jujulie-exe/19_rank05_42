#include "../include/RPN.hpp"

       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
RPN::RPN(const std::string* args, size_t size)
	: _result(INT_MIN)
{
/*	if (size > 10 )
		throw SizeToHight();*/
	if (!miniParser(args, size))
		throw errorParsing();
	this->_arrayFToperator[0] = &RPN::sum;
	this->_arrayFToperator[1] = &RPN::min;
	this->_arrayFToperator[2] = &RPN::mult;
	this->_arrayFToperator[3] = &RPN::div;
	this->_operatori[0] = "+";
	this->_operatori[1] = "-";
	this->_operatori[2] = "*";
	this->_operatori[3] = "/";
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
	std::stringstream ss(c);
	int rslt;
	ss >> rslt;
	return rslt;
}

static bool opAcepetd(const char c)
{
	return (c == '*' || c == '-' || c == '/' || c == '+');
}

void RPN::Operation( const char *oprt)
{
	int tmp1 = operandi.pop();
	int tmp2 = operandi.pop();
	for (size_t i = 0; operatori[i] != ""; ++i)
	{
		if ( oprtr == operatori[i])
		{
			this->_result = this->_arrayFToperator[i](tmp1, tmp2);
			this->operandi.push(this->_result);
		}
	}
	return ;
}

void RPN::executeRPN(const std::string* args, const size_t size)
{	
	for (size_t i = 0; i < size; ++i)
	{
		if (std::isdigit(args[i][0])){
			operandi.push(convertChar(args[i][0]);
		}
		else if ((opAcepetd(args[i][0]) && operandi.size() >= 2)){
			Operation(args[i][0]);
		}
		else{
			throw internalErrorRPN();
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
       /*♡♡♡♡♡♡♡♡♡♡♡UTILITY♡♡♡♡♡♡♡♡♡♡♡♡♡*/
int	RPN::sum(int nbr1, int nbr2) const;
{
	return (nbr1 + nbr2);
}

int	RPN::min(int nbr1, int nbr2) const;
{
	return (nbr1 - nbr2);
}

int	RPN::div(int nbr1, int nbr2) const;
{
	return (nbr1 / nbr2);
}

int	RPN::mult(int nbr1, int nbr2) const;
{
	return (nbr1 *  nbr2);
}



       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
RPN::~RPN()
{
    std::cout << "Destructor called" << std::endl;
    // dtor
}
       /*♡♡♡♡♡♡♡♡♡♡♡EXCEPTION♡♡♡♡♡♡♡♡♡♡♡♡♡*/
const char * RPN::errorParsing

/* std::ostream &operator<<(std::ostream &o, const RPN &rhs)
{
   o << rhs.getName() << std::endl;
   return o;
} */

