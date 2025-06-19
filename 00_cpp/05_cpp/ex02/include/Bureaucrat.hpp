#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#define MAX_GRADE 150
#define MIN_GRADE 1
#include <string>
#include <ostream>
#include <cstddef>
#include <iostream>
#include <ostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		/*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
		Bureaucrat(const std::string& nameREF, int n);	//cannon
		Bureaucrat(Bureaucrat const & src);	//Cannon
											//
		/*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
		std::string getName( void ) const;
		int			getGrade( void ) const;

		/*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
		Bureaucrat& operator=(Bureaucrat const & rsh);	//Cannon
														//
		/*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
		virtual ~Bureaucrat();	//Cannon
								//
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

		/*♡♡♡♡♡♡♡♡♡♡♡CLASS♡FT♡♡♡♡♡♡♡♡♡♡♡♡*/
		void	incrementa( void ) throw(GradeTooHighException);
		void	decrementa( void ) throw(GradeTooLowException);
		void	signForm( AForm* src );
		void	executeForm(AForm const & form) const;

	private:
		const std::string	name;
		int					grade;
		
		/*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
		Bureaucrat();	//cannon
};

	std::ostream &operator<<(std::ostream &o,  const Bureaucrat &rhs);
#endif // BUREAUCRAT_H
