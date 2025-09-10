#ifndef PMERGEME_H
#define PMERGEME_H
 
class PmergeMe
{
   public:
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       PmergeMe();  //cannon
       PmergeMe(PmergeMe const & src);   //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   size_t getNumberCmp( void ) const;
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   void	Ford-JohnsonVector(std::vector<int> &vecREF);

 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       PmergeMe& operator=(PmergeMe const & rsh);    //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~PmergeMe(); //Cannon
  private:
	   cmp(int a, int b);
	   size_t cmp;
};
// std::ostream &operator<<(std::ostream &o, const PmergeMe &rhs);
#endif // PMERGEME_H

