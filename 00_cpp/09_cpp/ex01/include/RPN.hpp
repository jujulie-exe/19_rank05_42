#ifndef RPN_H
#define RPN_H
 
class RPN
{
   public:
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   RPN(const str::string* & args, size_t size);
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   void calculator( void );
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~RPN(); //Cannon
  private:
       RPN(RPN const & src);   //Cannon
       RPN& operator=(RPN const & rsh);    //Cannon
       RPN();  //cannon
	   std::stack<int, std::list<int> >	operandi;
	   result int;
};
// std::ostream &operator<<(std::ostream &o, const RPN &rhs);
#endif // RPN_H

