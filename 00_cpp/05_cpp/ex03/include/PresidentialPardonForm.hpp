#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H
#include "AForm.hpp"
#include "Bureaucrat.hpp"
 
class PresidentialPardonForm : public AForm
{
   public:
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       PresidentialPardonForm(const std::string& targetREF);   //Cannon
       PresidentialPardonForm(PresidentialPardonForm const & src);   //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       PresidentialPardonForm& operator=(PresidentialPardonForm const & rsh);    //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~PresidentialPardonForm(); //Cannon
  private:
       PresidentialPardonForm();  //cannon
	   const std::string	_target;
  protected:
	   virtual void executeAction() const;
};
// std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &rhs);
#endif // PRESIDENTIALPARDONFORM_H

