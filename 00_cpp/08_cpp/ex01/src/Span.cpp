/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:46:09 by jfranco           #+#    #+#             */
/*   Updated: 2025/07/26 18:23:40 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
Span::Span(unsigned int size)
	: _size(size), _MaxDistance(0), _MinDistance(LLONG_MAX), _InterIndex(0)
{
	this->_array = new int[_size];
	if (_size > 0)
	{
		for (size_t i = 0; i < _size; ++i)
		{
			_array[i] = 0;
		}
	}
}

Span::Span()
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

Span::Span(Span const & src)
	: _size (src._size), _MaxDistance(src._MaxDistance), _MinDistance(src._MinDistance), _InterIndex(src._InterIndex)
{
    std::cout << "Copy constructor called" << std::endl;
	this->_array = new int[_size];
	if (_size > 0)
	{
		for (size_t i = 0; i < _size; ++i)
		{
			this->_array[i] = src._array[i];
		}
	}

}

       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
size_t	Span::shortestSpan( void )
{
	if (_MinDistance == LLONG_MAX)
	{
		searchSpan();
		if (_MinDistance == LLONG_MAX)
			throw NoSpan();
	}
	return _MinDistance;
}

size_t	Span::longestSpan( void )
{
	if (_MaxDistance == 0)
	{
		searchSpan();
		if (_MinDistance == 0)
			throw NoSpan();
	}
	return _MaxDistance;
}
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
void	Span::searchSpan( void )
{
	 if (_InterIndex <= 1) 
		 return;
	long long diff ;
	for (size_t i = 0; i < _InterIndex; ++i)
	{
		for (size_t y = 0; y < _InterIndex; ++y)
		{
			diff = std::llabs((long long)this->_array[i] - (long long)this->_array[y]);
			if ( diff > static_cast<long long>(_MaxDistance) && diff != 0)
			{
				_MaxDistance = diff;
			}
			if (diff < static_cast<long long>(_MinDistance) && diff != 0)
			{
				_MinDistance = diff;
			}
		}
	}
	//std::cout << "diff = " << diff << ", _MinDistance = " << _MinDistance << std::endl;
}

void	Span::addNumber( int nbr )
{
	if (_InterIndex < _size )
	{
		this->_array[_InterIndex] = nbr;
		_InterIndex++;
	}
	else
	{
		throw MaxSize();
	}
}
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
Span &Span::operator=( Span const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        // this->_n = rhs.getValue();
    }
    return *this;
}

       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
Span::~Span()
{
    std::cout << "Destructor called" << std::endl;
	delete[] this->_array;
    // dtor
}

       /*♡♡♡♡♡♡♡♡♡♡♡EXCEPTION♡♡♡♡♡♡♡♡♡♡♡♡♡*/
const char*	Span::MaxSize::what() const throw()
{
	return "Max size limit";
}
const char*	Span::NoSpan::what() const throw()
{
	return "No valid span";
}

/* std::ostream &operator<<(std::ostream &o, const Span &rhs)
{
   o << rhs.getName() << std::endl;
   return o;
} */

