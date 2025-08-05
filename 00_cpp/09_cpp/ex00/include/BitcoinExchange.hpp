#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H
 
class BitcoinExchange
{
   public:
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       BitcoinExchange();  //cannon
       BitcoinExchange(BitcoinExchange const & src);   //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   int	OpenAndParser(std::string const & FileName);
	   bool	stringParser(std::string const & strREF);
	   void	insertInMap(std::string const & strREF);
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       BitcoinExchange& operator=(BitcoinExchange const & rsh);    //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~BitcoinExchange(); //Cannon
  private:
	   std::map<std::string, int> _hisotry;
};
// std::ostream &operator<<(std::ostream &o, const BitcoinExchange &rhs);
#endif // BITCOINEXCHANGE_H

