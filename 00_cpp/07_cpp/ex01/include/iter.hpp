#ifndef ITER_HPP
# define ITER_HPP
#include <iostream>
#include <string>
#include <cctype>


template <typename T>
void printElement(const T& elem)
{
    std::cout << elem << " ";
}

template <typename T>
void printUppercase( T& elem)
{
	std::cout << std::hex << std::showbase
	 << std::uppercase << elem << " ";
}
void increment(int& x)
{
    ++x;
}

template <typename T, typename F >
void	iter(T *array, size_t lenghArray, F* func)
{
	for (size_t i = 0; i < lenghArray; ++i)
	{
		func(array[i]);
	}
}

#endif
