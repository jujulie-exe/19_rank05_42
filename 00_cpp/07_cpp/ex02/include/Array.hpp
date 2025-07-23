#ifndef ARRAY_H
#define ARRAY_H
#include <ostream>
#include <iostream>

template < typename T >
class Array
{
   public:
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       Array();  //cannon
       Array(size_t index);  //cannon
       Array(Array const & src);   //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       Array<T>& operator=(Array<T> const & rsh);    //Cannon
       T& operator[](int index);
       T& operator[](size_t index);

	   class IndexNotAllow : public std::exception
		{
			public:
				virtual const char* what() const throw();  // dichiarazione
		};
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~Array(); //Cannon
  private:
	   T	*_array;
	   size_t	_size;
};
#include "../src/Array.tpp"
// std::ostream &operator<<(std::ostream &o, const Array &rhs);
#endif // ARRAY_H

