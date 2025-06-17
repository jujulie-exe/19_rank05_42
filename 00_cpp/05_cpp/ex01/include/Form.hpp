#ifndef FORM_H
#define FORM_H
 
class Form
{
   public:
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       Form();  //cannon
       Form(Form const & src);   //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   std::string	getName() const;
	   int			getSignGrade() const;
	   int			getExecuteGrade() const;
	   bool			getIfSigned() const;
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   void	beSigned(const &Bureaucrat);
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       Form& operator=(Form const & rsh);    //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~Form(); //Cannon
  private:
	   const std::string name;
	   const int		sign_grade;
	   const int		execute_grade;
	   bool				IfSigned;
};
// std::ostream &operator<<(std::ostream &o, const Form &rhs);
#endif // FORM_H

