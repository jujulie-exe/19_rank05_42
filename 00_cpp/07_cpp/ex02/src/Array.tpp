#include "../include/Array.hpp"

       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
template < typename T >
Array<T>::Array(size_t size)
	: _size(size)
{
	this->_array = new T[size];
}

template < typename T >
Array<T>::Array()
	: _size(0)
{
	this->_array = new T[_size];
}

template < typename T >
Array<T>::Array(Array<T> const & src)
	: _size (src._size)
{
	this->_array = new T[this->_size];
	for (size_t i = 0; i < src._size; ++i){
		this->_array[i] = src._array[i];
	}
}

       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
template < typename T >
Array<T> &Array<T>::operator=( Array<T> const &rhs)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
		if (this->_array != NULL)
		{
			delete [] this->_array;
		}
		this->_size = rhs._size;
		this->_array = new T[rhs._size];
		for (size_t i = 0; i < rhs._size; ++i){
			this->_array[i] = rhs._array[i];
		}
    }
    return *this;
}
template < typename T >
T &Array<T>::operator[](int index)
{
	if (index < 0 || static_cast<size_t>(index) >= _size || _array == NULL)
	{
		throw IndexNotAllow();
	}
	return this->_array[index];
}

template < typename T >
T &Array<T>::operator[](size_t index)
{
	if (static_cast<size_t>(index) >= _size || _array == NULL)
	{
		throw IndexNotAllow();
	}
	return this->_array[index];
}

       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
template < typename T >
Array<T>::~Array()
{
	if (this->_array != NULL)
	{
		delete [] this->_array;
	}
	return ;
    // dtor
}
template < typename T >
const char	*Array<T>::IndexNotAllow::what() const throw()
{
	return ("Error: Invalid index");
}
/* std::ostream &operator<<(std::ostream &o, const Array &rhs)
{
   o << rhs.getName() << std::endl;
   return o;
} */

