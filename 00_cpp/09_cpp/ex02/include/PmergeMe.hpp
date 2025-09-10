#ifndef PMERGEME_H
#define PMERGEME_H
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <vector>  
#include <set>

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

 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       PmergeMe& operator=(PmergeMe const & rsh);    //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~PmergeMe(); //Cannon
  private:
	    bool ft_cmp(int a, int b);
	   std::set<int>	Jacobsthal(size_t maxNbr);
		size_t cmp;
	void	binaryInsertGroup(std::vector<int>& mainChain, const std::vector<int>& group, size_t SizePairs);
	void	printVec(std::vector<int> t) const;
};
// std::ostream &operator<<(std::ostream &o, const PmergeMe &rhs);
#endif // PMERGEME_H

