#include "../include/Array.hpp"

       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
Array::Array(size_t size)
	: _size(size);
{
	this->_array = new T[size];
}

Array::Array()
	: _size(0);
{
	this->_array = new T[_size];
}

Array::Array(Array const & src)
{
}

       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
Array &Array::operator=( Array const &rhs)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
		if (this->_array != NULL)
		{
			delete [] this->_array;
		}
		this->_array = new T[rhs->size];
		for (size_t i = 0; i < rhs->size; ++i){
			this->_array[i] = rhs->_array[i];
		}
    }
    return *this;
}

       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
Array::~Array()
{
    std::cout << "Destructor called" << std::endl;
    // dtor
}

/* std::ostream &operator<<(std::ostream &o, const Array &rhs)
{
   o << rhs.getName() << std::endl;
   return o;
} */

