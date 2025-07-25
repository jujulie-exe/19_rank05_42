#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H
#include "AForm.hpp"
#include "Bureaucrat.hpp"
 
class ShrubberyCreationForm : public AForm
{
   public:
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       ShrubberyCreationForm(const std::string& targetREF);  //cannon
       ShrubberyCreationForm(ShrubberyCreationForm const & src);   //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       ShrubberyCreationForm& operator=(ShrubberyCreationForm const & rsh);    //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~ShrubberyCreationForm(); //Cannon
  private:
	   const std::string _target;
       ShrubberyCreationForm();  //cannon
  protected:
	   virtual void executeAction() const;
};
// std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &rhs);
#endif // SHRUBBERYCREATIONFORM_H

