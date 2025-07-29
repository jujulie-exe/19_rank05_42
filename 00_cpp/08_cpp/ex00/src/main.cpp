
#include "../include/easyfind.hpp"

int	main()
{
	std::vector<int> v;
	v.push_back(9);
	v.push_back(10);
	v.push_back(100);
	v.push_back(-124);
	v.push_back(42);
	std::vector<int> vec;
	for(size_t i = 0; i < 100; ++i)
	{
		vec.push_back(rand());
	}
	std::list<int> L(vec.begin(), vec.end());
	std::vector<int>::const_iterator it = easyfind(v, 42);
	std::vector<int>::const_iterator itNoFind = easyfind(v, 1921);
	std::list<int>::const_iterator itList = easyfind(L, 39);
	printFind(itList, L);
	printFind(it, v);
	printFind(itNoFind, v);

}
