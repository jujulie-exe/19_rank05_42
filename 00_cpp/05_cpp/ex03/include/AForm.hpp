#ifndef AFORM_H
#define AFORM_H
#include "Bureaucrat.hpp"
#include <string>
#include <ostream>
#include <cstddef>
#include <iostream>
#include <ostream>
class Bureaucrat;

class AForm
{
   public:
		//EXCEPITION OVERDIDE CLASS
		class GradeTooHighException : public std::exception 
		{
		public:
			virtual const char* what() const throw();  // dichiarazione
		};
		class GradeTooLowException : public std::exception
		{
		public:
	        virtual const char* what() const throw(); // dichiarazione
	    };
		class NoSignedExeption : public std::exception
		{
		public:
	        virtual const char* what() const throw(); // dichiarazione
	    };

       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       AForm(const std::string& nameREF, int grd, int exe) ;  
       AForm(AForm const & src);   //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   std::string	getName() const;
	   int			getSignGrade() const;
	   int			getExecuteGrade() const;
	   bool			getIfSigned() const;
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   void	beSigned(Bureaucrat &ptr) throw(GradeTooLowException);
	   void	execute(Bureaucrat const & executor) const throw(GradeTooLowException, NoSignedExeption);
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       AForm& operator=(AForm const & rsh);    //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~AForm(); //Cannon
						

  private:
       AForm();  //cannon
	   const std::string name;
	   const int		sign_grade;
	   const int		execute_grade;
	   bool				IfSigned;
   protected:
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   virtual void	executeAction( void ) const = 0;
};
std::ostream &operator<<(std::ostream &o, const AForm &rhs);
#endif // FORM_H

