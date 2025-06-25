#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H
 
class ScalarConverter
{
   public:
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   static void	convert(const std::string& infoREF);
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
  private:
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       ScalarConverter();  //cannon
       ScalarConverter(ScalarConverter const & src);   //Cannon
													   //
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       ScalarConverter& operator=(ScalarConverter const & rsh);    //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~ScalarConverter(); //Cannon
};
// std::ostream &operator<<(std::ostream &o, const ScalarConverter &rhs);
#endif // SCALARCONVERTER_H

