
#include "../include/Span.hpp"
#define MAX_ALLOC 10000


void	AddInsp(Span &sp, int insrt)
{
	try
	{
		sp.addNumber(insrt);
	}
	catch (std::exception& e)
	{
		 std::cout << e.what() << '\n';
 	}
}

void	PrintEvent (Span &sp)
{
	try
	{
		std::cout << sp.shortestSpan() << std::endl;  
    	std::cout << sp.longestSpan() << std::endl;  
	}
	catch (std::exception& e)
	 {
		 std::cout << e.what() << '\n';
 	 }
}

void	MaxAlloc( void )
{
    Span sp = Span(MAX_ALLOC);  
	for (size_t i = 0; i < MAX_ALLOC; ++i)
	{
		AddInsp(sp, rand());
	}
	PrintEvent(sp);
}

void	TestExeption( void )
{
	Span	sp = Span(0);
	AddInsp(sp, rand());
	PrintEvent(sp);

}

void	TestOverFlows( void )
{
    Span TestOverFlows = Span( 100 );  
	AddInsp(TestOverFlows, INT_MIN);
	for (size_t i = 0; i < 97; ++i)
	{
		AddInsp(TestOverFlows, i);
	}
	AddInsp(TestOverFlows, INT_MAX);
	PrintEvent(TestOverFlows);
}
int main()  
{  
	TestOverFlows();
	TestExeption();
	MaxAlloc();
    return 0;  
}

