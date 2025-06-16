#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
 
class Bureaucrat
{
	public:
		//CTOR
		Bureaucrat(std::string &nameREF, int grade);	//cannon
		Bureaucrat(Bureaucrat const & src);	//Cannon
		//GETTER
		std::string getName( void ) const;
		int			getGrade( void ) const;
		//CLASS FUNCTION
		void	incrementa( void ) throw(GradeTooHighException);
		void	decrementa( void ) throw(GradeTooLowException);
		//OPERATOR
		Bureaucrat& operator=(Bureaucrat const & rsh);	//Cannon
		//DTOCR
		virtual ~Bureaucrat();	//Cannon
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
	private:
		const std::string	name;
		int					grade;
		Bureaucrat();	//cannon
};

	std::ostream &operator<<(std::ostream &o,  const Bureaucrat &rhs);
#endif // BUREAUCRAT_H
