#include <iostream>
#include <ostream>
#include "../include/Data.hpp"

#include "../include/Serializer.hpp"

int	main()
{
	Data n0;
	uintptr_t raw = Serializer::serialize(&n0);
	std::cout << n0.nbr << std::endl;
	std::cout << raw << std::endl;
	std::cout << Serializer::deserialize(raw) << std::endl;
	Data *n1 =	Serializer::deserialize(raw);
	std::cout << n1->nbr << std::endl;
	
	return (0);
}
