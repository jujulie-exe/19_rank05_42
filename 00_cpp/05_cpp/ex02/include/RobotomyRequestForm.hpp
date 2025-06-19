#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H
#include "AForm.hpp"
#include "Bureaucrat.hpp"
 
class RobotomyRequestForm : public AForm
{
   public:
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       RobotomyRequestForm(const std::string& targetREF);
       RobotomyRequestForm(RobotomyRequestForm const & src);   //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       RobotomyRequestForm& operator=(RobotomyRequestForm const & rsh);    //Cannon
																		   //
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~RobotomyRequestForm(); //Cannon
									   //
  private:
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
		RobotomyRequestForm();  //cannon
								
       /*♡♡♡♡♡♡♡♡♡♡♡VARIABLE♡♡♡♡♡♡♡♡♡♡♡♡♡*/
		const std::string	_target;	
		unsigned int		_n;
  protected:
	   virtual void executeAction( void ) const;
};
// std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &rhs);
#endif // ROBOTOMYREQUESTFORM_H

