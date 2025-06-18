#ifndef FORM_H
#define FORM_H
#include "Bureaucrat.hpp"
#include <string>
#include <ostream>
#include <cstddef>
#include <iostream>
#include <ostream>
#include "Form.hpp"
class Bureaucrat;

class Form
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

       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       Form(const std::string& nameREF, int grd, int exe) ;  
       Form(Form const & src);   //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   std::string	getName() const;
	   int			getSignGrade() const;
	   int			getExecuteGrade() const;
	   bool			getIfSigned() const;
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   void	beSigned(Bureaucrat &ptr) throw(GradeTooLowException);
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       Form& operator=(Form const & rsh);    //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~Form(); //Cannon
						

  private:
       Form();  //cannon
	   const std::string name;
	   const int		sign_grade;
	   const int		execute_grade;
	   bool				IfSigned;
};
std::ostream &operator<<(std::ostream &o, const Form &rhs);
#endif // FORM_H

