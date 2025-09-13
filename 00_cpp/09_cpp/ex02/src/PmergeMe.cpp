#include "../include/PmergeMe.hpp"

       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
static bool ft_cmp_global(int a, int b)
{
	return(b  < a);
}

bool PmergeMe::ft_cmp(int a, int b)
{
	this->cmp++;
	std::cout << "Confronto : " << a << " " << b << "\n";
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
	for (std::set<int>::reverse_iterator it = JacobList.rbegin(); it != JacobList.rend(); ++it, ++i) {
		size_t idx = *it * pairSize;
		if (idx + pairSize <= peding.size()) {
			std::vector<int> insert(peding.begin() + idx, peding.begin() + idx + pairSize);
			printVec(insert, "INSERT JACOB: ");
			binaryInsertGroup(main, insert, pairSize  - 1);
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
                binaryInsertGroup(main, insert, insert.size() - 1);
                printVec(main, "MAIN AFTER INSERT: ");
            }
        }
    }
}
void PmergeMe::FordJohnsonVector(std::vector<int>& vecREF, size_t pairSize) {
 size_t n = vecREF.size();

    if (pairSize >= n) {
        return;
    }

    printVec(vecREF, "LIST: ");

    // Confronta e scambia le coppie
	for (size_t i = 0; i + 2 * pairSize <= n; i += 2 * pairSize) {
    size_t leftMax  = i + pairSize - 1;
    size_t rightMax = i + 2 * pairSize - 1;

    std::cout << "Confronto blocchi per swap: " << vecREF[leftMax] << " vs " << vecREF[rightMax] << std::endl;
    
    if (rightMax < n && ft_cmp(vecREF[leftMax], vecREF[rightMax])) {
        std::cout << "Swapping blocchi: ";
        for (size_t k = i; k < i + pairSize; ++k) std::cout << vecREF[k] << " ";
        std::cout << "con ";
        for (size_t k = i + pairSize; k < i + 2 * pairSize; ++k) std::cout << vecREF[k] << " ";
        std::cout << std::endl;
        
        // METODO 1: Swap manuale (più sicuro)
        for (size_t j = 0; j < pairSize; ++j) {
            std::swap(vecREF[i + j], vecREF[i + pairSize + j]);
        }
        std::cout << "Dopo swap: ";
        for (size_t k = i; k < i + 2 * pairSize && k < n; ++k) std::cout << vecREF[k] << " ";
        std::cout << std::endl;
    }
}


    printVec(vecREF, "LIST: ");
    FordJohnsonVector(vecREF, pairSize * 2);
    std::cout << "-------" << pairSize << "\n";
    printVec(vecREF, "LIST: ");

    std::vector<int> b1anda; //main
    std::vector<int> other;  //pending
    std::vector<int> unpaired; //elementi che non possono essere accoppiati

    // Distribuzione degli elementi
	for (size_t i = 0; i < n; i += pairSize * 2) {
    bool canPairCompletely = (i + 2 * pairSize <= n);
    
    if (canPairCompletely) {
        if (pairSize == 1) {
            // CASO SPECIALE: confronto diretto dei due elementi
            if (ft_cmp(vecREF[i], vecREF[i + 1])) {
                other.push_back(vecREF[i + 1]);  // più piccolo -> pending
                b1anda.push_back(vecREF[i]);     // più grande -> main
                std::cout << "PIU PICCOLO " << vecREF[i + 1] << "\n";
                std::cout << "PIU GRANDE " << vecREF[i] << "\n";
            } else {
                other.push_back(vecREF[i]);      // più piccolo -> pending
                b1anda.push_back(vecREF[i + 1]); // più grande -> main
                std::cout << "PIU PICCOLO " << vecREF[i] << "\n";
                std::cout << "PIU GRANDE " << vecREF[i + 1] << "\n";
            }
        } else {
            // CASO GENERALE: confronta i rappresentanti dei blocchi
            size_t leftBlockStart = i;
            size_t rightBlockStart = i + pairSize;
            
            // I rappresentanti sono gli ultimi elementi di ogni blocco
            // (dopo il sorting, dovrebbero essere i più grandi di ogni blocco)
            size_t leftRepresentative = i + pairSize - 1;
            size_t rightRepresentative = i + 2 * pairSize - 1;
            
            std::cout << "Confronto blocchi: " << vecREF[leftRepresentative] 
                      << " vs " << vecREF[rightRepresentative] << std::endl;
            
            if (ft_cmp(vecREF[leftRepresentative], vecREF[rightRepresentative])) {
                // Il blocco di sinistra ha rappresentante più grande
                // Quindi: blocco destro -> pending, blocco sinistro -> main
                
                // Blocco destro (più piccolo) va in pending
                for (size_t j = rightBlockStart; j < rightBlockStart + pairSize; ++j) {
                    other.push_back(vecREF[j]);
                    std::cout << "PIU PICCOLO " << vecREF[j] << "\n";
                }
                
                // Blocco sinistro (più grande) va in main
                for (size_t j = leftBlockStart; j < leftBlockStart + pairSize; ++j) {
                    b1anda.push_back(vecREF[j]);
                    std::cout << "PIU GRANDE " << vecREF[j] << "\n";
                }
            } else {
                // Il blocco di sinistra ha rappresentante più piccolo o uguale
                // Quindi: blocco sinistro -> pending, blocco destro -> main
                
                // Blocco sinistro (più piccolo) va in pending
                for (size_t j = leftBlockStart; j < leftBlockStart + pairSize; ++j) {
                    other.push_back(vecREF[j]);
                    std::cout << "PIU PICCOLO " << vecREF[j] << "\n";
                }
                
                // Blocco destro (più grande) va in main  
                for (size_t j = rightBlockStart; j < rightBlockStart + pairSize; ++j) {
                    b1anda.push_back(vecREF[j]);
                    std::cout << "PIU GRANDE " << vecREF[j] << "\n";
                }
            }
        }
    } else {
        // blocco incompleto: prendi tutti i rimanenti come unpaired
        for (size_t j = i; j < n; ++j) {
            unpaired.push_back(vecREF[j]);
        }
        break;
    }
}
    // Inserisci il primo elemento di pending all'inizio di main (se esiste)
    // Solo per pairSize > 1, perché per pairSize == 1 gli elementi sono già ordinati correttamente
if (!other.empty()  && pairSize <= other.size()) {
    b1anda.insert(b1anda.begin(), other.begin(), other.begin() + pairSize);
    other.erase(other.begin(), other.begin() + pairSize);
   }
    printVec(b1anda, "MAIN: ");
    printVec(other, "PENDING: ");
    printVec(unpaired, "UNPAIRED: ");

    // Inserisci usando Jacobsthal
    insertWithJacob(b1anda, other, pairSize);
    insertREST(b1anda, other, pairSize);

    // Inserisci gli elementi unpaired alla fine
    if (!unpaired.empty()) {
        printVec(unpaired, "INSERTING UNPAIRED: ");
		if (1)
		{
			//binaryInsertGroup(b1anda, unpaired, unpaired.size() - 1);
			for (size_t i = 0; i < unpaired.size(); ++i)
			{
				std::vector<int>::iterator insertPos = std::lower_bound(b1anda.begin(), b1anda.end(), unpaired[i]);
				b1anda.insert(insertPos, unpaired.begin() + i, unpaired.begin() + i + 1);
			}
		}
		else
		{
			for (size_t i = 0; i < unpaired.size(); ++i)
			{
				b1anda.push_back(unpaired[i]);
			}
		}
    }

    // VERIFICA DI SICUREZZA
    if (b1anda.size() != vecREF.size()) {
        std::cout << "ATTENZIONE: Possibile perdita elementi! Expected: " << vecREF.size()
                  << ", Got: " << b1anda.size() << std::endl;
        // Il vecchio codice catch-all come fallback
        std::vector<int> missing;
        for (size_t idx = b1anda.size(); idx < vecREF.size(); ++idx) {
            missing.push_back(vecREF[idx]);
        }
        if (!missing.empty()) {
            printVec(missing, "ADDING MISSING: ");
			for (size_t i = 0; i < missing.size(); ++i)
			{
				std::vector<int>::iterator insertPos = std::lower_bound(b1anda.begin(), b1anda.end(), missing[i]);
				b1anda.insert(insertPos, missing.begin(), missing.end());
			}
            //binaryInsertGroup(b1anda, missing, missing.size() - 1);
        }
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


void PmergeMe::binaryInsertGroup(std::vector<int>& mainChain, const std::vector<int>& group, size_t pivotIndex) {
    // Verifica che l'indice sia valido
    if (pivotIndex >= group.size()) {
        std::cout << "ERRORE: pivotIndex " << pivotIndex << " >= group.size() " << group.size() << std::endl;
        return;
    }

    // Usa l'elemento all'indice specificato come pivot per binary search
    int pivotElement = group[pivotIndex];
    std::cout << pivotElement << " element MAX (using index " << pivotIndex << ")\n";

    // Trova la posizione dove inserire usando binary search sul pivot
    std::vector<int>::iterator insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), pivotElement);
	for (size_t i = 0; i < pivotIndex; ++i)
	{
		insertPos--;
	}

    if (insertPos != mainChain.end()) {
        std::cout << *insertPos << " VALUE INSERTPOS \n";
    } else {
        std::cout << "INSERT AT END\n";
    }
	ft_cmp_global(0,0);
    // Inserisci TUTTO il gruppo nella posizione trovata (come unità)
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

