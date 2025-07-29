#include "../include/MutantStack.hpp"

       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
template < typename T,  class container>
MutantStack<T, container>::MutantStack()
	: std::stack<T, container>()
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

template < typename T,  class container>
MutantStack<T, container>::MutantStack(MutantStack<T, container> const & src)
	: std::stack<T, container>( src )
{
    std::cout << "Copy constructor called" << std::endl;
    //*this = src;
}

       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
template < typename T,  class container >
typename std::stack<T, container>::container_type::iterator	MutantStack<T, container>::begin( void )
{
	return this->c.begin();
}

template < typename T,  class container >
typename std::stack<T, container>::container_type::iterator	MutantStack<T, container>::end( void )
{
	return this->c.end();
}
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
template < typename T,  class container >
MutantStack<T, container> &MutantStack<T, container>::operator=( MutantStack<T, container> const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
		this->c = rhs.c;
    }
    return *this;
}

       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
template < typename T,  class container >
MutantStack<T, container>::~MutantStack()
{
    std::cout << "Destructor called" << std::endl;
    // dtor
}

/* std::ostream &operator<<(std::ostream &o, const MutantStack &rhs)
{
   o << rhs.getName() << std::endl;
   return o;
} */

