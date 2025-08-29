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
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
void PmergeMe::pairList( size_t matriX, std::list<int>::iterator index)
{
	static std::list<int> tmp;
	std::list<int>::iterator start = index;
	index++;
	if (start == this->_c[matriX].end() || index == this->_c[matriX].end())
	{
		this->_c.push_back(tmp);
		tmp.clear();
		if (this->_c[matriX].size()  == 2)
			return ;
		pairList(matriX + 1, this->_c[matriX].begin());
		return ;
	} //riampiazzare con un funzione max
	if (*start > *index)
	{
		tmp.push_back(*start);
		this->_c[matriX].remove(*start);
	}
	else
	{
		tmp.push_back(*index);
		this->_c[matriX].remove(*index);
	}
	pairList(matriX, start++);
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

