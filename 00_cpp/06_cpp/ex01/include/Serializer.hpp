#ifndef SERIALIZER_H
#define SERIALIZER_H
#include <stdint.h>
 
#include <iostream>
#include <ostream>
#include "../include/Data.hpp"
class Serializer
{
   public:
	   static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
  private:
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       Serializer();  //cannon
       Serializer(Serializer const & src);   //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       Serializer& operator=(Serializer const & rsh);    //Cannon
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
       virtual ~Serializer(); //Cannon
};
// std::ostream &operator<<(std::ostream &o, const Serializer &rhs);
#endif // SERIALIZER_H

