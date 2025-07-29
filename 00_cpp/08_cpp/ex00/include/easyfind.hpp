#ifndef EASYFIND_HPP

# define EASYFIND_HPP
#include <ostream>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
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
	return std::find(continer.begin(), continer.end(), find);
}

#endif
