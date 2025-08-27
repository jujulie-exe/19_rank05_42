#ifndef RPN_H
#define RPN_H
#include <iostream>
#include <ostream>
#include <stack>
#include <list>
#include <limits.h>
#include <string>
#include <exception>
#include <sstream>
 
class RPN
{
	typedef int (RPN::*ftOperator)(int, int) const;
   public:
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   RPN(const std::string*  args, size_t size);
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~RPN(); //Cannon
  private:
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       RPN(RPN const & src);   //Cannon
       RPN& operator=(RPN const & rsh);    //Cannon
       RPN();  //cannon

       /*♡♡♡♡♡♡♡♡♡♡♡VARIABLE♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   std::stack<int, std::list<int> >	operandi;
	   //void (Validator::* _FunPTR[12])(std::vector<std::string>&);
	   ftOperator _arrayFToperator[4];
	   int _result;

       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
		void executeRPN(const std::string* args, const size_t size);
		bool miniParser(const std::string* args, const size_t size) const;
		void Operation( const char oprt);

       /*♡♡♡♡♡♡♡♡♡♡♡UTILITY♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   int sum(int nbr1, int nbr2) const;
	   int min(int nbr1, int nbr2) const;
	   int mult(int nbr1, int nbr2) const;
	   int div(int nbr1, int nbr2) const;
       /*♡♡♡♡♡♡♡♡♡♡♡EXCEPTION♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   class errorParsing : public std::exception{
		   virtual const char * what() const throw();
	   };
	   class internalErrorRPN : public std::exception{
		   virtual const char * what() const throw();
	   };
};
// std::ostream &operator<<(std::ostream &o, const RPN &rhs);
#endif // RPN_H

