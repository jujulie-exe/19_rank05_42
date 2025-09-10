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
	(void)src;
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

    if (file.good()){
        std::cout << "File stream is valid: " << filename;
		std::cout << "\n\n";
	}
    return true;
}
static	void	trimSpace(std::string& tmp)
{
		tmp.erase(0, tmp.find_first_not_of(" 	"));
		tmp.erase(tmp.find_last_not_of(" 	") + 1);
}

static	float	StringConvert(std::string const & strREF)
{
		float	value;
		std::stringstream ss(strREF);
		ss >> value;
		return (value);
}

bool	BitcoinExchange::IsValideDate(std::tm const &tmREF)
{
	std::tm copy = tmREF;
	std::mktime(&copy);
	return ( copy.tm_year == tmREF.tm_year
			&& copy.tm_mon == tmREF.tm_mon 
			&& copy.tm_mday == tmREF.tm_mday);
}
void	BitcoinExchange::printError( int nbr, std::string const & strREF) const
{
	if (nbr < 0)
	{
		std::cerr << "Error: ";
		if ( nbr == -1 )
			std::cerr << "bad input " << strREF;
		else if ( nbr == -2 )
			std::cerr << "not valide date ";
		else if ( nbr == -3 )
			std::cerr << "bad input " << strREF;
		else if ( nbr == -4 )
			std::cerr << "too large a number.  ";
		else if ( nbr == -5 )
			std::cerr << "empty input ";
		else if ( nbr == -6 )
			std::cerr << "bad input " << strREF;
		else if ( nbr == -7 )
			std::cerr << "not a positive number  ";
		std::cerr << "\n";
		return ;
	}
	else
	{
		return ;
	}
}

void BitcoinExchange::findInMap(std::time_t time, float value, std::string const & strREF) const
{
	std::map<std::time_t, float>::const_iterator itB = this->_history.begin();
	std::map<std::time_t, float>::const_iterator itE = this->_history.end();
	itE--;
	if ( time > itE->first )
	{
		std::time_t timestamp = itE->first;
		std::string timestr = ctime(&timestamp);
		timestr.erase(0 , timestr.size() - 5);
		timestr.erase(4 , timestr.size());
		std::cout  << "WARNING: the date is before than the database the last available date is "  << timestr  << " " << strREF << " => " << itE->second * value << "\n";
		return ;
	}
	if ( time < itB->first )
	{
		std::time_t timestamp = itB->first;
		std::string timestr = ctime(&timestamp);
		timestr.erase(0 , timestr.size() - 5);
		timestr.erase(4 , timestr.size());
		std::cout  << "WARNING: the date is earlier than the database the first available date is "  << timestr  << " "
			<< strREF << " => " << itB->second * value << "\n";
		return ;
	}
	std::map<std::time_t, float>::const_iterator it = this->_history.find(time);
	if (it != this->_history.end())
	{
		std::cout  << strREF << " => " << it->second * value << "\n";
		return ;
	}
	std::time_t day = 86400;
	while (it == this->_history.end())
	{
		time = time - day;
		it = this->_history.find(time);
	}
	if (it != this->_history.end())
	{
		std::cout  << strREF << " => " << it->second * value << "\n";
		return ;
	}

}

int	BitcoinExchange::stringParserINP(std::string const & strREF, std::string sprt)
{
	if (strREF.empty())
		return -5;
	size_t found = strREF.find_first_not_of("1234567890-. " + sprt);
	if (found!=std::string::npos)
	{
		std::cout << "Syntax error: " << strREF[found];
		std::cout << " at position " << found << " ";
		return -6;
	}
	size_t	posFisrtMinus = strREF.find("-");
	size_t	posLastMinus = strREF.rfind("-");
	size_t	posSeparator = strREF.find(sprt);
	if (posFisrtMinus!=std::string::npos && posLastMinus!=std::string::npos && posSeparator!=std::string::npos)
	{
		if (posFisrtMinus != 4)
		{
			return -1;
		}
		if (posLastMinus != 7)
		{
			if (static_cast<long>(StringConvert(strREF.substr(posLastMinus))) < 0)
				return -7;
			else
				return -1;
		}
		if (posSeparator != 11)
		{
			return -1;
		}
		std::string tmp = strREF.substr(0, posSeparator);
		std::string tmpFinal = strREF.substr(posSeparator + 1);
		trimSpace(tmp);
		trimSpace(tmpFinal);
		size_t pos = tmp.find_first_not_of("1234567890-");
		size_t posFinal = tmpFinal.find_first_not_of("1234567890.-");
		if (pos!=std::string::npos || posFinal!=std::string::npos)
		{
			return -1;
		}
		std::tm info = {};
		info.tm_year = static_cast<int>(StringConvert( tmp.substr(0, 4) ) - 1900);
		info.tm_mon = static_cast<int>(StringConvert( tmp.substr(5, 2)   ) - 1);
		info.tm_mday = static_cast<int>(StringConvert( tmp.substr(8, 2)));
		if (IsValideDate (info) == false)
			return -2;
		std::time_t t = std::mktime(&info);
		if (t == -1 )
			return -3;
		if (static_cast<long long>( StringConvert(tmpFinal) ) > 1001 || static_cast<long long>( StringConvert(tmpFinal) ) < 0)	
		{
			if (static_cast<long long>( StringConvert(tmpFinal) ) > 1001)
				return -4;
			else
				return -7;
		}
		findInMap(t, StringConvert(tmpFinal), tmp);
	}
	else
	{
		return -1;
	}
	return 0;
}


bool	BitcoinExchange::stringParserDB(std::string const & strREF, std::string sprt)
{
	if (strREF.empty())
		return false;
	size_t found = strREF.find_first_not_of("1234567890-. " + sprt);
	if (found!=std::string::npos)
	{
		std::cout << "Syntax error: " << strREF[found];
		std::cout << " at position " << found << '\n';
		return false;
	}
	size_t	posFisrtMinus = strREF.find("-");
	size_t	posLastMinus = strREF.rfind("-");
	size_t	posSeparator = strREF.find(sprt);
	if (posFisrtMinus!=std::string::npos && posLastMinus!=std::string::npos && posSeparator!=std::string::npos)
	{
		if (posFisrtMinus != 4)
		{
			return false;
		}
		if (posLastMinus != 7)
		{
			return false;
		}
		if (posSeparator != 10)
		{
			return false;
		}
		std::string tmp = strREF.substr(0, posSeparator);
		std::string tmpFinal = strREF.substr(posSeparator + 1);
		trimSpace(tmp);
		trimSpace(tmpFinal);
		size_t pos = tmp.find_first_not_of("1234567890-");
		size_t posFinal = tmpFinal.find_first_not_of("1234567890.");
		if (pos!=std::string::npos || posFinal!=std::string::npos)
		{
			return false;
		}
		std::tm info = {};
		info.tm_year = static_cast<int>(StringConvert( tmp.substr(0, 4) ) - 1900);
		info.tm_mon = static_cast<int>(StringConvert( tmp.substr(5, 2)   ) - 1);
		info.tm_mday = static_cast<int>(StringConvert( tmp.substr(8, 2)));
		if (IsValideDate (info) == false)
			return false;
		std::time_t t = std::mktime(&info);
		if (t == -1 )
			return false;
		_history.insert(std::make_pair(t, StringConvert(tmpFinal)));
	}
	else
	{
		return false;
	}
	return (true);
}

int	BitcoinExchange::OpenAndParserINP(std::string const & FileName )
{
	std::ifstream	FileSrc(FileName.c_str());
	if (!CheckFileStream(FileSrc, FileName))
	{
		return (0);
	}
	std::string out;
	while (std::getline(FileSrc, out))
	{
		printError(stringParserINP(out, "|"), out);
	}
	return (1);
}

int	BitcoinExchange::OpenAndParserDB(std::string const & FileName )
{
	std::ifstream	FileSrc(FileName.c_str());
	if (!CheckFileStream(FileSrc, FileName))
	{
		return (0);
	}
	std::string out;
	while (std::getline(FileSrc, out))
	{
		if (stringParserDB(out) == false)
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

