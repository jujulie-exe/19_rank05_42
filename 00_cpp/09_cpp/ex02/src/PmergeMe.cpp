#include "../include/PmergeMe.hpp"

       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
bool PmergeMe::cmp(int a, int b)
{
	this->cmp++;
	return(b > a);
}

PmergeMe::PmergeMe()
{
    std::cout << "Default constructor called" << std::endl;
    // ctor
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    //*this = src;
}

       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
void PmergeMe::FordJohnsonVector(std::vector<int>& vecREF, size_t pairSize) {
    size_t n = vecREF.size();

    if (pairSize >= n)
        return;

    for (size_t i = 0; i + 2 * pairSize <= n; i += 2 * pairSize) {
        if (cmp(vecREF[i], vecREF[i + pairSize])) {
            for (size_t j = 0; j < pairSize; ++j) {
                std::swap(vecREF[i + j], vecREF[i + pairSize + j]);
            }
        }
    }
    FordJohnsonVector(vecREF, pairSize * 2);
	std::vector<int> b1anda;
	std::vector<int> other;
	for (size_t i = 0; i + pairSize <= vecREF.size(); i += pairSize * 2) {
		for (size_t j = i; j < i + pairSize && j < vecREF.size(); ++j) {
			b1anda.push_back(vecREF[j]);
		}
		for (size_t j = i + pairSize; j < i + 2 * pairSize && j < vecREF.size(); ++j) {
			other.push_back(vecREF[j]);
		}
	}
	if (!b1anda.empty()) {
		other.insert(other.begin(), b1anda[0]); 
		b1anda.erase(b1anda.begin());
	}
	//add jacob and binarySort
}

void PmergeMe::binaryInsert(std::deque<int>::iterator nb, std::deque<int>::iterator low, std::deque<int>::iterator high)
{
    size_t lowIdx = low - d.begin();
    size_t highIdx = high - d.begin();

    int value = *nb;

    while (cmp(lowIdx < highIdx)) {
        size_t midIdx = lowIdx + (highIdx - lowIdx) / 2;
        if (value <= d[midIdx])
            highIdx = midIdx;
        else
            lowIdx = midIdx + 1;
    }
	//TODO:INSERIRE TUTTO UN CONTINER IN POSIZIONE GIUSTA
    d.insert(vecREF.begin() + lowIdx, value);
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

