#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H
#include <ostream>
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <utility>
#include <ctime>
 
class BitcoinExchange
{
   public:
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       BitcoinExchange();  //cannon
       BitcoinExchange(BitcoinExchange const & src);   //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   int	OpenAndParserDB(std::string const & FileName);
	   int	OpenAndParserINP(std::string const & FileName);
	   bool	stringParserDB(std::string const & strREF, std::string sprt = ",");
	   int	stringParserINP(std::string const & strREF, std::string sprt = ",");
	   bool	IsValideDate(std::tm const &tmREF);
	   void	printError(int nbr, std::string const & strREF) const;
	   void	findInMap(std::time_t time, float value, std::string const & strREF) const;
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       BitcoinExchange& operator=(BitcoinExchange const & rsh);    //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~BitcoinExchange(); //Cannon
  private:
	   std::map<std::time_t, float> _history;
};
// std::ostream &operator<<(std::ostream &o, const BitcoinExchange &rhs);
#endif // BITCOINEXCHANGE_H

