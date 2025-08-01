#include "../include/ScalarConverter.hpp"
#include <iomanip>  // per std::fixed


double get_pos_inf() {
    return std::numeric_limits<double>::infinity();
}

double get_neg_inf() {
    return -std::numeric_limits<double>::infinity();
}

double get_nan() {
    return std::numeric_limits<double>::quiet_NaN();
}


static int solve(const std::string& s )
{
	unsigned int i = 0;
	int flags = 0;
	if(s[0] == '-')
		i = 1;
   while (i < s.length())
   {
	    if (s[i] == '.')
        {
            flags++;
            if (flags > 1)
                return 0; // più di un punto
        }
		else if (s[i] == 'f')
		{
			 if (i != s.length() - 1)
				return 0;
		}
        else if (!std::isdigit(s[i]))
        {
            return 0; // carattere non valido
        }
		i++;
   }
   return (1);
}

static double	getDouble(const std::string& d)
{
	double db;
	char c;

	std::stringstream ff(d);
	if (d.size() == 1 && !std::isdigit( d[0]))
	{
		ff >> c;
		return (static_cast<double>(c));
	}
	ff >> db;
	return db;
}

static long long	getChar(const std::string& ch)
{
	char c;
	long long n;
	std::stringstream ss(ch);

	if (ch.size() == 1 && !std::isdigit( ch[0]))
		ss >> c;
	else
	{
		ss >> n;
		return n;
	}
	return (static_cast<long long>(c));
}
#include <limits.h>
void	ScalarConverter::convert(const std::string& infoREF)
{
	if ((((static_cast<int>(getDouble(infoREF))) == 0 && infoREF[0] != '0')) || (!solve(infoREF) && infoREF.length() > 1) || infoREF.empty())
	{
		int i = 0;
		std::string info[] = { "+inf", "+inff", "-inf", "-inff" , "nanf", "nan", ""};
		while (!info[i].empty())
		{
			SpecialFunc funcs[] = { get_pos_inf, get_pos_inf, get_neg_inf, get_neg_inf, get_nan, get_nan };
			if (info[i] == infoREF)
			{
				std::cout << "double: " << funcs[i]() << std::endl;
				std::cout << "float: " << funcs[i]() << "f" << std::endl;
				std::cout << "char: impossible" << std::endl;
				std::cout << "int:  impossible" << std::endl;
				return ;
			}
			i++;
		}
		std::cerr << "INVALID STRING" << std::endl;
		return ;
	}
	if(std::isprint(static_cast<char>(getChar(infoREF))))
		std::cout << "ASCII: " << (static_cast<char>(getChar(infoREF)));
	else
		std::cout << "char: Non displayable";
	std::cout << std::endl;
	if(getChar(infoREF) <= INT_MAX && getChar(infoREF) >= INT_MIN)
		std::cout << "int is: <" << getChar(infoREF) << ">";
	else
		std::cout << "int is: <" << "impossible" << ">";
	std::cout << std::endl;
	if (getDouble(infoREF) < static_cast<double>(1 << 24) && getDouble(infoREF) > static_cast<double>(-(1 << 24)))
		std::cout << "float is: [" << std::fixed << std::setprecision(1) << (static_cast<float>(getDouble(infoREF))) << "f]";
	else
		std::cout << "float is: <" << "impossible" << ">";
	std::cout << std::endl;
	std::cout << "Double is:{" << std::fixed << std::setprecision(1) << getDouble(infoREF) << "} ";
	std::cout << std::endl;
}










       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
ScalarConverter::ScalarConverter()
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	(void)src;
    std::cout << "Copy constructor called" << std::endl;
    //*this = src;
}

       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
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

