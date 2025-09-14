
#include "../include/PmergeMe.hpp"

void	PmergeMe::insertWithJacob(std::deque<int> &main, std::deque<int> &peding, size_t pairSize)
{
	std::set<int> JacobList = Jacobsthal(peding.size() / pairSize);
	size_t i = 0;
	for (std::set<int>::reverse_iterator it = JacobList.rbegin(); it != JacobList.rend(); ++it, ++i) {
		size_t idx = *it * pairSize;
		if (idx + pairSize <= peding.size()) {
			std::deque<int> insert(peding.begin() + idx, peding.begin() + idx + pairSize);
			binaryInsertGroup(main, insert, pairSize  - 1);
		}
		
	}
}
static bool nonPresent(const std::set<int>& Jacob, size_t nbr)
{
    return Jacob.find(static_cast<int>(nbr)) == Jacob.end();
}

void PmergeMe::insertREST(std::deque<int> &main, std::deque<int> &peding, size_t pairSize)
{
    std::set<int> JacobList = Jacobsthal(peding.size() / pairSize);

    size_t totalBlocks = peding.size() / pairSize;

    for (size_t block = 0; block < totalBlocks; ++block) {
        if (nonPresent(JacobList, block)) {
            size_t idxi = block * pairSize;
            if (idxi + pairSize <= peding.size()) {
                std::deque<int> insert(peding.begin() + idxi, peding.begin() + idxi + pairSize);
                binaryInsertGroup(main, insert, insert.size() - 1);
            }
        }
    }
}
void PmergeMe::FordJohnsonVector(std::deque<int>& vecREF, size_t pairSize) {
 size_t n = vecREF.size();

    if (pairSize >= n) {
        return;
    }
	for (size_t i = 0; i + 2 * pairSize <= n; i += 2 * pairSize) {
		size_t leftMax  = i + pairSize - 1;
		size_t rightMax = i + 2 * pairSize - 1;
		if (rightMax < n && ft_cmp(vecREF[leftMax], vecREF[rightMax])) {
			for (size_t j = 0; j < pairSize; ++j) {
				std::swap(vecREF[i + j], vecREF[i + pairSize + j]);
			}
		}
	}


    FordJohnsonVector(vecREF, pairSize * 2);
    std::deque<int> b1anda; //main
    std::deque<int> other;  //pending
    std::deque<int> unpaired; //elementi che non possono essere accoppiati

	for (size_t i = 0; i < n; i += pairSize * 2) {
    bool canPairCompletely = (i + 2 * pairSize <= n);
    if (canPairCompletely && pairSize * 2 < vecREF.size()) {
        if (pairSize == 1) {
            if (ft_cmp(vecREF[i], vecREF[i + 1])) {
                other.push_back(vecREF[i + 1]);  
                b1anda.push_back(vecREF[i]);     
            }
			else
			{
                other.push_back(vecREF[i]);      
                b1anda.push_back(vecREF[i + 1]); 
            }
        }
		else
		{
            size_t leftBlockStart = i;
            size_t rightBlockStart = i + pairSize;
            size_t leftRepresentative = i + pairSize - 1;
            size_t rightRepresentative = i + 2 * pairSize - 1;
            if (ft_cmp(vecREF[leftRepresentative], vecREF[rightRepresentative])) {
                for (size_t j = rightBlockStart; j < rightBlockStart + pairSize; ++j) {
                    other.push_back(vecREF[j]);
                }
                for (size_t j = leftBlockStart; j < leftBlockStart + pairSize; ++j) {
                    b1anda.push_back(vecREF[j]);
                }
            }
			else
			{
                for (size_t j = leftBlockStart; j < leftBlockStart + pairSize; ++j) {
                    other.push_back(vecREF[j]);
                }
                for (size_t j = rightBlockStart; j < rightBlockStart + pairSize; ++j) {
                    b1anda.push_back(vecREF[j]);
                }
            }
        }
    }
	else
	{
        for (size_t j = i; j < n; ++j) {
            unpaired.push_back(vecREF[j]);
        }
		break;
	}
	}
	if (!other.empty()  && pairSize <= other.size()) {
		b1anda.insert(b1anda.begin(), other.begin(), other.begin() + pairSize);
		other.erase(other.begin(), other.begin() + pairSize);
	}
    insertWithJacob(b1anda, other, pairSize);
    insertREST(b1anda, other, pairSize);
    if (!unpaired.empty()) {
		if (b1anda.empty() || pairSize == 1)
		{
			//binaryInsertGroup(b1anda, unpaired, unpaired.size() - 1);
			for (size_t i = 0; i < unpaired.size(); ++i)
			{
				std::deque<int>::iterator insertPos = std::lower_bound(b1anda.begin(), b1anda.end(), unpaired[i]);
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
    vecREF = b1anda;
}


void PmergeMe::binaryInsertGroup(std::deque<int>& mainChain, const std::deque<int>& group, size_t pivotIndex) {
    if (pivotIndex >= group.size()) {
        return;
    }
    int pivotElement = group[pivotIndex];
    std::deque<int>::iterator insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), pivotElement);
	insertPos = std::lower_bound(mainChain.begin(), insertPos, pivotElement);
    mainChain.insert(insertPos, group.begin(), group.end());
}


