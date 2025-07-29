#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H
#include <stack>
#include <ostream>
#include <iostream>
#include <deque>
#include <vector>
#include <list>

template < typename T,  class container=std::deque<T> >
class MutantStack : public std::stack<T, container>
{
   public:
	typedef typename std::stack<T, container>::container_type::iterator iterator;
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       MutantStack();  //cannon
       MutantStack(MutantStack const & src);   //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   iterator begin( void );
	   iterator end( void );
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       MutantStack& operator=(MutantStack const & rsh);    //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~MutantStack(); //Cannon
  private:
};
#include "../src/MutantStack.tpp"
// std::ostream &operator<<(std::ostream &o, const MutantStack &rhs);
#endif // MUTANTSTACK_H

