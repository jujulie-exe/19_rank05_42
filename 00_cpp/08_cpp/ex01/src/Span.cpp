/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:46:09 by jfranco           #+#    #+#             */
/*   Updated: 2025/07/29 18:20:31 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
Span::Span(unsigned int size)
	: _size(size), _MaxDistance(0), _MinDistance(LLONG_MAX), _InterIndex(0), _SpanCal(false)
{
}

Span::Span()
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

Span::Span(Span const & src)
	: _size (src._size), _MaxDistance(src._MaxDistance), _MinDistance(src._MinDistance), _InterIndex(src._InterIndex), _SpanCal(src._SpanCal), _VecInt(src._VecInt), _CopyKeyValue(src._CopyKeyValue)
{
    std::cout << "Copy constructor called" << std::endl;

}

       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
size_t	Span::shortestSpan( void )
{
	if (_SpanCal != true)
	{
		searchSpan();
		this->_SpanCal = true;
	}
	if (_MinDistance == LLONG_MAX)
		throw NoSpan();
	return _MinDistance;
}

size_t	Span::longestSpan( void )
{
	if (_SpanCal != true)
	{
		searchSpan();
		this->_SpanCal = true;
	}
	if (_MaxDistance == 0)
		throw NoSpan();
	return _MaxDistance;
}
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
void	Span::searchSpan( void )
{
	 if (_InterIndex <= 1) 
		 return;
	long long diff ;
	_MaxDistance = 0;
	_MinDistance = LLONG_MAX;
	std::vector<int>::iterator it = _VecInt.begin();
	while (it != _VecInt.end())
	{
		_CopyKeyValue.insert(*it);
		++it;
	}
	if (_CopyKeyValue.size() > 1)
	{
		std::set<int>::iterator itSetBeg = _CopyKeyValue.begin();
		std::set<int>::iterator itEnd = _CopyKeyValue.end();
		std::set<int>::iterator itSetAf = _CopyKeyValue.begin();
		itEnd--;
		_MaxDistance = std::llabs(static_cast<long long>(*itSetBeg) - static_cast<long long>(*itEnd));
		while (itSetBeg != _CopyKeyValue.end())
		{
			diff = std::labs(static_cast<long long>(*itSetAf )- static_cast<long long>(*itSetBeg));
			if (diff < static_cast<long long>(_MinDistance) && diff != 0)
			{
				_MinDistance = diff;
			}
			itSetAf = itSetBeg;
			++itSetBeg;
		}
	}
}

void	Span::addNumber( int nbr )
{
	if (_InterIndex < _size )
	{
		this->_VecInt.push_back(nbr);
		this->_SpanCal = false;
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
		this->_size = rhs._size;
		this->_MaxDistance = rhs._MaxDistance;
		this->_MinDistance = rhs._MinDistance;
		this->_InterIndex = rhs._InterIndex;
		this->_SpanCal = rhs._SpanCal;
		this->_VecInt = rhs._VecInt;
		this->_CopyKeyValue = rhs._CopyKeyValue;
    }
    return *this;
}

       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
Span::~Span()
{
    std::cout << "Destructor called" << std::endl;
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

