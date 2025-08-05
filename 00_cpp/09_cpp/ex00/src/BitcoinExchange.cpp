#include "../include/BitcoinExchange.hpp"

       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
BitcoinExchange::BitcoinExchange()
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    //*this = src;
}

       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
static bool CheckFileStream(std::ifstream& file, const std::string& filename) 
{
    if (!file.is_open())
	{
        std::cout << "Failed to open configuration file: " << filename;
		std::cout << "\n\n";
        return false;
    }

    if (file.bad()) 
	{
        std::cout << "I/O error while accessing file: " << filename;
		std::cout << "\n\n";
        return false;
    }

    if (file.fail()) 
	{
        std::cout << "Logical error on file stream for: " << filename;
		std::cout << "\n\n";
        return false;
    }

    if (file.eof()) 
	{
        std::cout << "End of file reached immediately for: " << filename;
		std::cout << "\n\n";
        return false;
    }

    if (file.good())
        std::cout << "File stream is valid: " << filename;
	std::cout << "\n\n";
    return true;
}
static	void	trimSpace(std::string& tmp)
{
		tmp.erase(0, tmp.find_first_not_of(" 	"));
		tmp.erase(tmp.find_last_not_of(" 	") + 1);
}

bool	BitcoinExchange::stringParser(std::string const & strREF)
{
	size_t found = strREF.find_first_not_of("1234567890-| ");
	if (found!=std::string::npos)
	{
		std::cout << "Syntax error: " << strREF[found];
		std::cout << " at position " << found << '\n';
		return false;
	}
	size_t	posFisrtMinus = strREF.find("-");
	size_t	posLastMinus = strREF.rfind("-");
	size_t	posSeparator = strREF.find("|");
	if (posFisrtMinus!=std::string::npos && posLastMinus!=std::string::npos && posSeparator!=std::string::pos)
	{
		if (posFisrtMinus != 4)
			return false;
		if (posLastMinus != 7)
			return false;
		if (posSeparator != 11)
			return false;
		std::string tmp = strREF.substr(0, posSeparator - 1);
		std::string tmpFinal = strREF.substr(posSeparator + 1);
		trimSpace(tmp);
		trimSpace(tmpFinal);
		size_t pos = tmp.find_first_not_of("1234567890-");
		size_t posFinal = tmp.find_first_not_of("1234567890");
		if (pos!=std::string::npos || posFinal!=std::string::npos)
		{
			return false;
		}

	}
	else
	{
		return false;
	}
	return (true);
}

int	BitcoinExchange::OpenAndParser(std::string const & FileName)
{
	std::ifstream	FileSrc(FileName);
	if (!CheckFileStream(FileSrc))
	{
		return (0);
	}
	std::string out;
	while (std::getline(src, out))
	{
		if (stringParser(out) == true)
		{
			insertInMap(out);
		}
		else
		{
			return (0);
		}
	}
	return (1);
	
}
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
BitcoinExchange &BitcoinExchange::operator=( BitcoinExchange const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        // this->_n = rhs.getValue();
    }
    return *this;
}

       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
BitcoinExchange::~BitcoinExchange()
{
    std::cout << "Destructor called" << std::endl;
    // dtor
}

/* std::ostream &operator<<(std::ostream &o, const BitcoinExchange &rhs)
{
   o << rhs.getName() << std::endl;
   return o;
} */

