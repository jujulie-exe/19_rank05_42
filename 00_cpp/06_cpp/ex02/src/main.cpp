	
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include "../include/Base.hpp"
void identify(Base* p)
{ 
	A *a;
	B *b;
	C *c;
	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);
	if (a)
		std::cout << "tipo A" << std::endl;
	if (c)
		std::cout << "tipo C" << std::endl;
	if (b)
		std::cout << "tipo B" << std::endl;
	return ;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "tipo A" << std::endl;
	}
	catch(...)
	{
	}

	try
	{
		B&	b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "tipo B" << std::endl;
	}
	catch(...)
	{
	}

	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "tipo C" << std::endl;
	}
	catch(...)
	{
	}


}

static int		increment( void )
{
	static int n = 1;

	return ++n;
}

Base* generate(void)
{
	Base *ptr;
	int	 nbr = increment() % 3;
	if (nbr == 0)
		return ptr = new C;
	else if (nbr == 1)
		return ptr = new A;
	else
		return ptr = new B;
}

int		main()
{
	Base *ptr0 = generate();
	Base *ptr1 = generate();
	Base *ptr2 = generate();
	identify(ptr1);
	identify(ptr2);
	identify(ptr0);
	//REF
	identify(*ptr1);
	identify(*ptr2);
	identify(*ptr0);
	delete ptr0;
	delete ptr1;
	delete ptr2;

	return (0);
}
