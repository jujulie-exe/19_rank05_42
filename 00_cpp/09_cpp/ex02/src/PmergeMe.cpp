#include "../include/PmergeMe.hpp"

       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
bool PmergeMe::ft_cmp(int a, int b)
{
	this->cmp++;
	return(b  < a);
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
void	PmergeMe::insertWithJacob(std::vector<int> &main, std::vector<int> &peding, size_t pairSize)
{
	std::set<int> JacobList = Jacobsthal(peding.size() / pairSize);
	size_t i = 0;
	for (std::set<int>::iterator it = JacobList.begin(); it != JacobList.end(); ++it, ++i) {
		size_t idx = *it * pairSize;
		if (idx + pairSize <= peding.size()) {
			std::vector<int> insert(peding.begin() + idx, peding.begin() + idx + pairSize);
			printVec(insert, "INSERT JACOB: ");
			binaryInsertGroup(main, insert, pairSize - 1);
			printVec(main, "MAIN AFETR INSERT: ");
		}
		
	}
}
static bool nonPresent(const std::set<int>& Jacob, size_t nbr)
{
    return Jacob.find(static_cast<int>(nbr)) == Jacob.end();
}

void PmergeMe::insertREST(std::vector<int> &main, std::vector<int> &peding, size_t pairSize)
{
    std::set<int> JacobList = Jacobsthal(peding.size() / pairSize);

    size_t totalBlocks = peding.size() / pairSize;

    for (size_t block = 0; block < totalBlocks; ++block) {
        if (nonPresent(JacobList, block)) {
            size_t idxi = block * pairSize;
            if (idxi + pairSize <= peding.size()) {
                std::vector<int> insert(peding.begin() + idxi, peding.begin() + idxi + pairSize);
                printVec(insert, "INSERT REST: ");
                binaryInsertGroup(main, insert, pairSize - 1);
                printVec(main, "MAIN AFTER INSERT: ");
            }
        }
    }
}


void PmergeMe::FordJohnsonVector(std::vector<int>& vecREF, size_t pairSize) {
    size_t n = vecREF.size();

    if (pairSize >= n)
	{
        return;
	}

	printVec(vecREF, "LIST: ");
    for (size_t i = 0; i + 2 * pairSize <= n; i += 2 * pairSize) {
		if (i + pairSize < vecREF.size() && ft_cmp(vecREF[i], vecREF[i + pairSize])){
            for (size_t j = 0; j < pairSize; ++j) {
                std::swap(vecREF[i + j], vecREF[i + pairSize + j]);
            }
        }
    }
	printVec(vecREF, "LIST: ");
    FordJohnsonVector(vecREF, pairSize * 2);
	std::cout << "-------" << pairSize << "\n";
	printVec(vecREF, "LIST: ");
	std::vector<int> b1anda; //main tutti i piu grandi e davanti il piu piccolo
	std::vector<int> other; //pending i piu piccoli 
	for (size_t i = 0; i + pairSize <= vecREF.size(); i += pairSize * 2) {
		for (size_t j = i; j < i + pairSize && j < vecREF.size(); ++j) {
			other.push_back(vecREF[j]);
			std::cout << "PIU PICCOLO" << vecREF[j] << "\n";
		}
		for (size_t j = i + pairSize; j < i + 2 * pairSize && j < vecREF.size(); ++j) {
			b1anda.push_back(vecREF[j]);
			std::cout << "PIU GRANDE" << vecREF[j] << "\n";
		}
	}
	if (!b1anda.empty() && pairSize < other.size() && pairSize != 0) {
		b1anda.insert(b1anda.begin(), other.begin(), other.begin() + pairSize);
		other.erase(other.begin(), other.begin() + pairSize);
	}
	printVec(b1anda, "MAIN: ");
	printVec(other, "PEDDING: ");
	insertWithJacob(b1anda, other, pairSize);
	insertREST(b1anda, other, pairSize);
	if (b1anda.size() != vecREF.size()) {
		std::vector<int> insert;
		std::cout << "Diffret size " << vecREF.size() << " " << b1anda.size() << " "<< vecREF.size() - b1anda.size() << "\n";
    for (size_t i = b1anda.size(); i < vecREF.size(); ++i) {
        insert.push_back(vecREF[i]);
    }
		printVec(insert, "INSERT REST: ");
		printVec(b1anda, "LIST: ");
		binaryInsertGroup(b1anda, insert, (insert.size() - 1));
		printVec(b1anda, "LIST: ");
	}
	vecREF = b1anda;
}
void	PmergeMe::printVec(std::vector<int> t, const std::string &MSG) const
{
	std::cout << MSG;
	for (size_t i = 0; i < t.size(); ++i)
	{
		std::cout << t[i] << " ";
	}
	std::cout << "\n";
}
void PmergeMe::binaryInsertGroup(std::vector<int>& mainChain, const std::vector<int>& group, size_t SizePairs) {
    if (group.size() < SizePairs)
		return;
    //int maxElement = *std::max_element(group.begin(), group.end());
	int maxElement = group[SizePairs];
	std::cout << maxElement << "element MAX \n";
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

