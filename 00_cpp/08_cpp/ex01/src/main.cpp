
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

void TestCopyConstructor()
{
    std::cout << " \n Test Copy Constructor\n";
    Span original(3);
    AddInsp(original, 10);
    AddInsp(original, 20);
    AddInsp(original, 30);
    PrintEvent(original);

    Span copied(original);  // Copy constructor
    std::cout << "Copied span:\n";
    PrintEvent(copied);
}

void TestIdenticalValues()
{
    std::cout << " \n Test Identical Values\n";
    Span s(5);
    for (int i = 0; i < 5; ++i)
        AddInsp(s, 42);  // Tutti i valori uguali

    PrintEvent(s);  // Deve lanciare NoSpan (nessuna differenza valida)
}

void TestSingleValue()
{
    std::cout << " \n Test Single Value\n";
    Span s(5);
    AddInsp(s, 99);  // Un solo elemento

    PrintEvent(s);  // Deve lanciare NoSpan
}


void TestAssignmentOperator()
{
    std::cout << " \n Test Assignment Operator\n";
    Span a(3);
    AddInsp(a, 1);
    AddInsp(a, 2);
    AddInsp(a, 3);
    PrintEvent(a);

    Span b(3);
    b = a;  // Assignment operator
    std::cout << "Assigned span:\n";
    PrintEvent(b);
}

void	addDopoCacolo( void )
{
	Span s(5);
	s.addNumber(10);
	s.addNumber(20);
	std::cout << "first short: " << s.shortestSpan() << std::endl;
	s.addNumber(11);
	std::cout << "After add a new value: " << s.shortestSpan() << std::endl;
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
	std::cout << "\n Test int MAX \n";
	TestOverFlows();
	std::cout << "\n Test Exeption \n";
	TestExeption();
	std::cout << "\n Test MaxAlloc \n";
	MaxAlloc();
	std::cout << "\n Test AfterCalc \n";
	addDopoCacolo();
	TestCopyConstructor();
	TestIdenticalValues();
	TestSingleValue();
	TestAssignmentOperator();
    return 0;  
}

