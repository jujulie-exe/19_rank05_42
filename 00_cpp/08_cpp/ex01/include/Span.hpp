#ifndef SPAN_H
#define SPAN_H
#include <stddef.h>
#include <iostream>
#include <ostream>
#include <limits.h>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#define SSIZE_MIN (-SSIZE_MAX - 1)
 
class Span
{
   public:
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       Span(unsigned int size);  //cannon
       Span(Span const & src);   //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   size_t	shortestSpan( void );
	   size_t	longestSpan( void ) ;
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   void addNumber( int nbr);
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       Span& operator=(Span const & rsh);    //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~Span(); //Cannon
  private:
       Span();  //cannon
				
       /*♡♡♡♡♡♡♡♡♡♡♡VARIABLE♡♡♡♡♡♡♡♡♡♡♡♡♡*/
		unsigned int		_size;
		size_t				_MaxDistance;
		size_t				_MinDistance;
		size_t				_InterIndex;
		bool			  	_SpanCal;
		std::vector<int>	_VecInt;
		std::set<int>		_CopyKeyValue;

       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   void	searchSpan( void );

		class MaxSize: public std::exception
		{
		  virtual const char* what() const throw();
		};
		class NoSpan: public std::exception
		{
		  virtual const char* what() const throw();
		};

};
// std::ostream &operator<<(std::ostream &o, const Span &rhs);
#endif // SPAN_H

