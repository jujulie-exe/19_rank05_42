#include "../include/PmergeMe.hpp"

       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
PmergeMe::PmergeMe(const std::string* arNbr, size_t size)
{
	std::list<int> tmp;
	size_t i = 0;
	while ( i < size)
	{
		tmp.push_back(atoi(arNbr[i].c_str()));
		i++;
	}
	this->_c.push_back(tmp);
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    //*this = src;
}

       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
std::list<int>::iterator	PmergeMe::getStart( void ) 
{
	std::vector<std::list<int> >::iterator it = this->_c.begin();
	return it->begin();
}

void PmergeMe::printTreeList() const
{
    int livello = 0;
    for (std::vector<std::list<int> >::const_iterator it = this->_c.begin(); it != this->_c.end(); ++it)
    {
        std::cout << "Livello " << livello << ":\n";
        printList(it->begin(), it->end());
        std::cout << "\n";
        ++livello;
    }
}

void PmergeMe::printList(std::list<int>::const_iterator begin, std::list<int>::const_iterator end) const
{
    while (begin != end)
    {
        std::cout << *begin << " ";
        ++begin;
    }
}
#include <algorithm>
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
static std::list<int>::iterator& max(std::list<int>::iterator & it1, std::list<int>::iterator& it2 )
{
	if (*it1 > *it2)
		return it1;
	else
		return it2;
}

static std::list<int>::iterator& min(std::list<int>::iterator & it1, std::list<int>::iterator& it2 )
{
	if (*it1 > *it2)
		return it2;
	else
		return it1;
}
static int JacobsthalRECU(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

std::set<int>	PmergeMe::Jacobsthal(size_t maxNbr)
{
	std::set<int> tmp;
	int result = -1;
	int index = 0;
	while (result <= maxNbr)
	{
		resutl = JacobsthalRECU(index);
		if (result <= static_cast<int>(maxNbr))
			tmp.insert(result);
		index++;
	}
	return tmp;
}

#include <algorithm>    // std::sort
void PmergeMe::pairList( size_t matriX, std::list<int>::iterator it1)
{
	static std::list<int> tmpMax;
	static std::list<int> tmpMin;
	std::list<int>::iterator it2 = it1;
	if (this->_c[matriX].size() == 1)
		return ;
	it2++;
	if (it1 == this->_c[matriX].end() || it2 == this->_c[matriX].end())
	{
		this->_c[matriX].clear();
		this->_c[matriX].swap(tmpMin);
		if (it1 != this->_c[matriX].end())
			tmpMax.push_back(*it1);
		tmpMax.sort();
		this->_c.push_back(tmpMax);
		tmpMax.clear();
		pairList(matriX + 1, this->_c[matriX + 1].begin());
		return ;
	}
	tmpMax.push_back(*(max(it1, it2)));
	tmpMin.push_back(*(min(it1, it2)));
	it2++;
	pairList(matriX, it2);
}

void PmergeMe::executeSort(void)
{
	std::set<int> JacobList = Jacobsthal(this->_c[0].size());
	//TODO confronto;
	this->_c.erase(this->_c.begin())
}

 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
PmergeMe &PmergeMe::operator=( PmergeMe const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        // this->_n = rhs.getValue();
    }
    return *this;
}

       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
PmergeMe::~PmergeMe()
{
    std::cout << "Destructor called" << std::endl;
    // dtor
}

/* std::ostream &operator<<(std::ostream &o, const PmergeMe &rhs)
{
   o << rhs.getName() << std::endl;
   return o;
} */

