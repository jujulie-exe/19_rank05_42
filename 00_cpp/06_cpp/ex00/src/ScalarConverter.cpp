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


static int solve( std::string s )
{
   for( int i = 0; i < s.length(); i++ )
   {
      if( s[i] != '.' && !std::isdigit( s[i] ))
         return 0;
   }
   return 1;
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

static int	getChar(const std::string& ch)
{
	char c;
	int n;
	std::stringstream ss(ch);

	if (ch.size() == 1 && !std::isdigit( ch[0]))
		ss >> c;
	else
	{
		ss >> n;
		return n;
	}
	return (static_cast<int>(c));
}

void	ScalarConverter::convert(const std::string& infoREF)
{
	if ((static_cast<int>(getDouble(infoREF))) == 0 && infoREF[0] != '0')
	{
		double d;
		int i = 0;
		std::string info[] = { "+inf", "+inff", "-inf", "-inff" , "nanf", "nan", ""};
		while (!info[i].empty())
		{
			SpecialFunc funcs[] = { get_pos_inf, get_pos_inf, get_neg_inf, get_neg_inf, get_nan, get_nan };
			if (info[i] == infoREF)
			{
				std::cout << funcs[i]() << std::endl;
				return ;
			}
			i++;
		}
		std::cerr << "INVALID STRING" << std::endl;
		return ;
	}
	std::cout << "Double is:{" << std::fixed << std::setprecision(4) << getDouble(infoREF) << "} ";
	std::cout << "float is: ["<< std::fixed << std::setprecision(2) << getDouble(infoREF) << "f]";
	std::cout << " int is: <" << getChar(infoREF) << ">";
	if( getChar(infoREF) >= 41 && getChar(infoREF) < 128)
		std::cout << " ASCII: " << (static_cast<char>(getChar(infoREF)));
	else
		std::cout << " Carratere ascii non disponibile ";
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

