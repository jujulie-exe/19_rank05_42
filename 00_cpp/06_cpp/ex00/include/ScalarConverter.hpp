#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H
 
#include <sstream>
#include <iostream>
#include <ostream>
#include <ctype.h>
#include <limits>
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
typedef double (*SpecialFunc)();
double get_pos_inf();
double get_neg_inf();
double get_nan();

// std::ostream &operator<<(std::ostream &o, const ScalarConverter &rhs);
#endif // SCALARCONVERTER_H

