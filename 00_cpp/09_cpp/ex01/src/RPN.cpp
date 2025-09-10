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
	(void)src;
    //*this = src;
}

       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
bool	RPN::miniParser(const std::string* args, const size_t size) const
{
	for (size_t i = 0; i < size; ++i)
	{
		if (args[i].length() > 1 || args[i].empty() == true)
		{
			std::cerr << "Syntax error:  " << args[i] << "\n";
			return false;
		}
		size_t found = args[i].find_first_not_of("1234567890-+/*");
		if ( found!=std::string::npos )
			return false;
	}
	return true;
}

static int convertChar(const std::string c)
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

void RPN::Operation( const char oprt)
{
	char operatori[6] = "+-*/\0";
	for (size_t i = 0; operatori[i] != '\0'; ++i)
	{
		if ( oprt == operatori[i])
		{
			int tmp1 = this->operandi.top();
			this->operandi.pop();
			int tmp2 = this->operandi.top();
			this->_result = (this->*(_arrayFToperator[i]))(tmp2, tmp1);
			this->operandi.pop();
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
			this->operandi.push(convertChar(static_cast<std::string>(args[i])));
		}
		else if ((opAcepetd(args[i][0]) && operandi.size() >= 2)){
			Operation(args[i][0]);
		}
		else{
			throw internalErrorRPN();
		}
	}
	if (this->operandi.size() == 1)
	{
		std::cout << "Result is: " << this->operandi.top() << "\n";
	}
	else
	{
		std::cerr << "Error in RPN" << "\n";
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
int	RPN::sum(int nbr1, int nbr2) const
{
	return (nbr1 + nbr2);
}

int	RPN::min(int nbr1, int nbr2) const
{
	return (nbr1 - nbr2);
}

int	RPN::div(int nbr1, int nbr2) const
{
	return (nbr1 / nbr2);
}

int	RPN::mult(int nbr1, int nbr2) const
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
const char * RPN::errorParsing::what( void ) const throw()
{
	return "error in parsing";
}
const char * RPN::internalErrorRPN::what( void ) const throw()
{
	return "error internal RPN";
}

/* std::ostream &operator<<(std::ostream &o, const RPN &rhs)
{
   o << rhs.getName() << std::endl;
   return o;
} */

