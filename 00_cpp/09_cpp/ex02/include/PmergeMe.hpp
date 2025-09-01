#ifndef PMERGEME_H
#define PMERGEME_H
#include <stack>
#include <list>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <set>
#include <iostream>
#include <time.h>

 
class PmergeMe
{
   public:
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   PmergeMe(const std::string* arNbr, size_t size);
       PmergeMe(PmergeMe const & src);   //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   void printTreeList( void ) const;
	   void printTreeDeque( void ) const;
	   std::deque<int>::iterator getStartDeque( void );
	   size_t	getSizeDeque( void ) const;

	   template <typename Iterator>
	   void printList(Iterator begin, Iterator end) const
	   {
		   while (begin != end)
		   {
			   std::cout << *begin << " ";
			   ++begin;
		   }
	   }
	   size_t	getSize( void ) const;
	   std::list<int>::iterator	getStart( void );
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
		void	pairList( size_t matriX, std::list<int>::iterator it1);
		void	executeSortList(void);
		void	executeSortDeque(void);
		std::set<int>	Jacobsthal(size_t maxNbr);
		void	binaryInsert(std::list<int>::iterator nb, std::list<int>::iterator low, std::list<int>::iterator high);
		void	binaryInsert(std::deque<int>::iterator nb, std::deque<int>::iterator low, std::deque<int>::iterator high);
		void	pairDeque( size_t matriX, std::deque<int>::iterator it1);
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~PmergeMe(); //Cannon
  private:
       PmergeMe& operator=(PmergeMe const & rsh);    //Cannon
	   std::vector<std::list<int> > _c;
	   std::deque<std::deque<int> > _d;
       //PmergeMe();  //cannon
};
// std::ostream &operator<<(std::ostream &o, const PmergeMe &rhs);
#endif // PMERGEME_H

