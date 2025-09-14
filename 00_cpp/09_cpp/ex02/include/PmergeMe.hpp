#ifndef PMERGEME_H
#define PMERGEME_H
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <vector>  
#include <deque>
#include <set>
#include <algorithm>

class PmergeMe
{
   public:
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       PmergeMe();  //cannon
       PmergeMe(PmergeMe const & src);   //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   size_t getNumberCmp( void ) const;
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   void	FordJohnsonVector(std::vector<int> &vecREF, size_t pairSize);
	   void	FordJohnsonVector(std::deque<int> &vecREF, size_t pairSize);

 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       PmergeMe& operator=(PmergeMe const & rsh);    //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~PmergeMe(); //Cannon
  private:
	    bool ft_cmp(int a, int b);
	   std::set<int>	Jacobsthal(size_t maxNbr);
		size_t cmp;
	void	binaryInsertGroup(std::vector<int>& mainChain, const std::vector<int>& group, size_t SizePairs);
	void	printVec(std::vector<int> t, const std::string &MSG) const;
	void	insertWithJacob(std::vector<int> &main, std::vector<int> &peding, size_t pairSize);
	void	insertREST(std::vector<int> &main, std::vector<int> &peding, size_t pairSize);
	void	binaryInsertGroup(std::deque<int>& mainChain, const std::deque<int>& group, size_t SizePairs);
	void	printVec(std::deque<int> t, const std::string &MSG) const;
	void	insertWithJacob(std::deque<int> &main, std::deque<int> &peding, size_t pairSize);
	void	insertREST(std::deque<int> &main, std::deque<int> &peding, size_t pairSize);
};
// std::ostream &operator<<(std::ostream &o, const PmergeMe &rhs);
#endif // PMERGEME_H

