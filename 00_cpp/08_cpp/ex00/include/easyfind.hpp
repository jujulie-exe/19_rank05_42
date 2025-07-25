#ifndef EASYFIND_HPP

# define EASYFIND_HPP
#include <ostream>
#include <vector>
#include <iostream>
#include <list>
template < typename T >
void printFind(typename T::const_iterator it, const T& continer)
{
	if ( it != continer.end())
		std::cout << "Find " << *it << "\n";
	else
		std::cout << "Nothing Find "<< "\n";
}

template < typename T >
typename T::const_iterator easyfind( const T& continer, int find)
{
	typename T::const_iterator it = continer.begin();
	while (it != continer.end())
	{
		if ( *it == find )
			return it;
		++it;
	}
	return continer.end();
}

#endif
