#ifndef INTERN_H
#define INTERN_H
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
 
class Intern
{
   public:
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       Intern();  //cannon
       Intern(Intern const & src);   //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   AForm *makeForm(const std::string& name, const std::string& target) const;
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       Intern& operator=(Intern const & rsh);    //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~Intern(); //Cannon
  private:
	   AForm *CreateRobotomyRequestForm(const std::string &REF) const;
	   AForm *CreatePresidentialPardonForm(const std::string &REF) const;
	   AForm *CreateShrubberyCreationForm(const std::string &REF) const;
	   AForm*	(Intern::*_FunPTR[3])(const std::string &REF) const;
};
// std::ostream &operator<<(std::ostream &o, const Intern &rhs);
#endif // INTERN_H

