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

 
class PmergeMe
{
   public:
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   PmergeMe(const std::string* arNbr, size_t size);
       PmergeMe(PmergeMe const & src);   //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   void printTreeList( void ) const;
	   void printList(std::list<int>::const_iterator begin, std::list<int>::const_iterator end) const;
	   std::list<int>::iterator	getStart( void );
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
		void pairList( size_t matriX, std::list<int>::iterator index);
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       PmergeMe& operator=(PmergeMe const & rsh);    //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~PmergeMe(); //Cannon
  private:
	   std::vector<std::list<int> > _c;
       //PmergeMe();  //cannon
};
// std::ostream &operator<<(std::ostream &o, const PmergeMe &rhs);
#endif // PMERGEME_H

