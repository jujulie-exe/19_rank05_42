#include "../include/PmergeMe.hpp"

       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
bool PmergeMe::ft_cmp(int a, int b)
{
	this->cmp++;
	return(b < a);
}

PmergeMe::PmergeMe()
	: cmp(0)
{

    std::cout << "Default constructor called" << std::endl;
    // ctor
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
    std::cout << "Copy constructor called" << std::endl;
	(void)src;
    //*this = src;
}

       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
size_t PmergeMe::getNumberCmp( void ) const
{
	return this->cmp;
}
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
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
void PmergeMe::FordJohnsonVector(std::vector<int>& vecREF, size_t pairSize) {
    size_t n = vecREF.size();

    if (pairSize >= n)
        return;

    for (size_t i = 0; i + 2 * pairSize <= n; i += 2 * pairSize) {
        if (ft_cmp(vecREF[i], vecREF[i + pairSize])) {
            for (size_t j = 0; j < pairSize; ++j) {
                std::swap(vecREF[i + j], vecREF[i + pairSize + j]);
            }
        }
    }
    FordJohnsonVector(vecREF, pairSize * 2);
	std::vector<int> b1anda; //main
	std::vector<int> other; //pending
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

	std::set<int> JacobList = Jacobsthal(other.size() / pairSize);
	{
	size_t i = 0;
	for (std::set<int>::iterator it = JacobList.begin(); it != JacobList.end(); ++it, ++i) {
		size_t idx = *it * pairSize;
		if (idx + pairSize <= other.size()) {
			std::vector<int> insert(other.begin() + idx, other.begin() + idx + pairSize);
			std::cout << "INSERT: ";
			printVec(insert);
			std::cout << "\n";
			binaryInsertGroup(b1anda, insert, pairSize);
		}
	}
	}

//	for(size_t i = 0; i < JacobList.size(); ++i)
//	{
//		int idx = static_cast<size_t>(JacobList[i]);
//		if (idx + pairSize <= other.size()) {
//			std::vector<int> insert(other.begin() + idx, other.begin() + idx + pairSize);
//			binaryInsertGroup(b1anda, other, pairSize);
//		}
//	}
	//add jacob and binarySort
// Add elementi dispari (rimanenti) alla main chain
	size_t remainder = vecREF.size() % ( 2 * pairSize);
	if (remainder != 0) {
	    size_t start = vecREF.size() - remainder;
	    for (size_t i = start; i != 0; --i) {
	        b1anda.push_back(vecREF[i]);
	    }
	}
	vecREF = b1anda;
}
void	PmergeMe::printVec(std::vector<int> t) const
{
	for (size_t i = 0; i < t.size(); ++i)
	{
		std::cout << t[i];
	}
}
void PmergeMe::binaryInsertGroup(std::vector<int>& mainChain, const std::vector<int>& group, size_t SizePairs) {
    if (group.size() <= SizePairs)
		return;
    //int maxElement = *std::max_element(group.begin(), group.end());
	int maxElement = group[SizePairs];
    std::vector<int>::iterator insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), maxElement);
    mainChain.insert(insertPos, group.begin(), group.end());
}

//void PmergeMe::binaryInsert(std::deque<int>::iterator nb, std::deque<int>::iterator low, std::deque<int>::iterator high)
//{
//    size_t lowIdx = low - d.begin();
//    size_t highIdx = high - d.begin();
//
//    int value = *nb;
//
//    while (cmp(lowIdx < highIdx)) {
//        size_t midIdx = lowIdx + (highIdx - lowIdx) / 2;
//        if (value <= d[midIdx])
//            highIdx = midIdx;
//        else
//            lowIdx = midIdx + 1;
//    }
//	//TODO:INSERIRE TUTTO UN CONTINER IN POSIZIONE GIUSTA
//    d.insert(vecREF.begin() + lowIdx, value);
//}
 
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

