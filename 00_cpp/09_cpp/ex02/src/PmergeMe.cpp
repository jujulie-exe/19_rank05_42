#include "../include/PmergeMe.hpp"

       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
PmergeMe::PmergeMe(const std::string* arNbr, size_t size)
{
	std::list<int> tmp;
	std::deque<int> tmpD;
	size_t i = 0;
	while ( i < size)
	{
		tmp.push_back(atoi(arNbr[i].c_str()));
		tmpD.push_back(atoi(arNbr[i].c_str()));
		i++;
	}
	this->_c.push_back(tmp);
	this->_d.push_back(tmpD);
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
    std::cout << "Copy constructor called" << std::endl;
	(void)src;
    //*this = src;
}

       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
std::list<int>::iterator	PmergeMe::getStart( void ) 
{
	std::vector<std::list<int> >::iterator it = this->_c.begin();
	return it->begin();
}

size_t	PmergeMe::getSize( void ) const
{
	return this->_c.size();
}

std::deque<int>::iterator	PmergeMe::getStartDeque( void ) 
{
	std::deque<std::deque<int> >::iterator it = this->_d.begin();
	return it->begin();
}

size_t	PmergeMe::getSizeDeque( void ) const
{
	return this->_d.size();
}

void PmergeMe::printTreeList() const
{
    int livello = 0;
    for (std::vector<std::list<int> >::const_iterator it = this->_c.begin(); it != this->_c.end(); ++it)
    {
        printList(it->begin(), it->end());
        std::cout << "\n";
        ++livello;
    }
}

void PmergeMe::printTreeDeque() const
{
    int livello = 0;
    for (std::deque<std::deque<int> >::const_iterator it = this->_d.begin(); it != this->_d.end(); ++it)
    {
        printList(it->begin(), it->end());
        std::cout << "\n";
        ++livello;
    }
}

/*void PmergeMe::printList(std::list<int>::const_iterator begin, std::list<int>::const_iterator end) const
{
    while (begin != end)
    {
        std::cout << *begin << " ";
        ++begin;
    }
}*/
#include <algorithm>
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
// Funzione template per max
template <typename Iterator>
Iterator& max(Iterator& it1, Iterator& it2)
{
    if (*it1 > *it2)
        return it1;
    else
        return it2;
}

// Funzione template per min
template <typename Iterator>
Iterator& min(Iterator& it1, Iterator& it2)
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
    return JacobsthalRECU(n - 1) + 2 * JacobsthalRECU(n - 2);
}

std::set<int>	PmergeMe::Jacobsthal(size_t maxNbr)
{
	std::set<int> tmp;
	int result = -1;
	int index = 0;
	while (static_cast<int>( maxNbr ) >= result)
	{
		result = JacobsthalRECU(index);
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
		if (it1 != this->_c[matriX].end())
			tmpMax.push_back(*it1);
		this->_c[matriX].clear();
		this->_c[matriX].swap(tmpMin);
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

void PmergeMe::pairDeque( size_t matriX, std::deque<int>::iterator it1)
{
	static std::deque<int> tmpMax;
	static std::deque<int> tmpMin;
	std::deque<int>::iterator it2 = it1;
	if (this->_d[matriX].size() == 1 || this->_d[matriX].empty())
		return ;
	it2++;
	if (it1 == this->_d[matriX].end() || it2 == this->_d[matriX].end())
	{
		if (it1 != this->_d[matriX].end())
			tmpMax.push_back(*it1);
		this->_d[matriX].clear();
		this->_d[matriX].swap(tmpMin);
		this->_d.push_back(tmpMax);
		tmpMax.clear();
		pairDeque(matriX + 1, this->_d[matriX + 1].begin());
		return ;
	}
	tmpMax.push_back(*(max(it1, it2)));
	tmpMin.push_back(*(min(it1, it2)));
	it2++;
	pairDeque(matriX, it2);
}

void PmergeMe::binaryInsert(std::list<int>::iterator nb, std::list<int>::iterator low, std::list<int>::iterator high)
{
	while (low != high)
	{
		std::list<int>::iterator mid = low;
        std::advance(mid, std::distance(low, high) / 2);
		if (*nb <= *mid)
		{
			high = mid;
		}
		else
		{
			++mid;
			low = mid;
		}
	}
	this->_c[1].insert(low,*nb);

}
void PmergeMe::binaryInsert(std::deque<int>::iterator nb, std::deque<int>::iterator low, std::deque<int>::iterator high)
{
    std::deque<int>& d = this->_d[1]; 
    size_t lowIdx = low - d.begin();  
    size_t highIdx = high - d.begin();

    int value = *nb;

    while (lowIdx < highIdx) {
        size_t midIdx = lowIdx + (highIdx - lowIdx) / 2;
        if (value <= d[midIdx])
            highIdx = midIdx;
        else
            lowIdx = midIdx + 1;
    }

    d.insert(d.begin() + lowIdx, value);
}


void PmergeMe::executeSortDeque(void)
{
	std::set<int> JacobList = Jacobsthal(this->_d[0].size() - 1);
	std::set<int>::reverse_iterator itSet = JacobList.rbegin();
	while (!this->_d[0].empty())
	{
		std::deque<int>::iterator it = this->_d[0].begin();
		if (itSet != JacobList.rend()){
			std::advance(it, *itSet);
			itSet++;
		}
		binaryInsert(it, this->_d[1].begin(), this->_d[1].end());
		this->_d[0].erase(it);
	}
	this->_d.erase(this->_d.begin());
}

void PmergeMe::executeSortList(void)
{
	std::set<int> JacobList = Jacobsthal(this->_c[0].size() - 1);
	std::set<int>::reverse_iterator itSet = JacobList.rbegin();
	while (!this->_c[0].empty())
	{
		std::list<int>::iterator it = this->_c[0].begin();
		if (itSet != JacobList.rend()){
			std::advance(it, *itSet);
			itSet++;
		}
		binaryInsert(it, this->_c[1].begin(), this->_c[1].end());
		this->_c[0].remove(*it);
	}
	this->_c.erase(this->_c.begin());
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

