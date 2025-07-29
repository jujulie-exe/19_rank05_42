

#include "../include/MutantStack.hpp"
void	testCopy( void )
{
	MutantStack<std::string, std::vector<std::string> > mstack;
	mstack.push("Hello");
	mstack.push("word");
	mstack.push("save");
	mstack.push("me");
	mstack.push("pls");
	MutantStack<std::string, std::vector<std::string> >	tmp;
	tmp = mstack;
	MutantStack<std::string, std::vector<std::string> >::iterator it = tmp.begin();
	while (it != tmp.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << "\n\n";
}

void	vectorContainer( void )
{
	MutantStack<std::string, std::vector<std::string> > mstack;
	mstack.push("Hello");
	mstack.push("word");
	mstack.push("save");
	mstack.push("me");
	mstack.push("pls");
	MutantStack<std::string, std::vector<std::string> >::iterator it = mstack.begin();
	while (it != mstack.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << "\n\n";
}

void	listContainer( void )
{
	MutantStack<int, std::list<int> > mstack;
	int i = 0;
	while (i < 100)
	{
		mstack.push(i);
		++i;
	}
	MutantStack<int, std::list<int> >::iterator it = mstack.begin();
	while (it != mstack.end())
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	deffContainer( void )
{
	MutantStack<int > mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

int main()
{
	// test std::stack don't expose metod of continer expose just push //
	/*std::stack<int, std::vector<int> > test;
	test.push_back(1);*/
	deffContainer();
	listContainer();
	vectorContainer();
	testCopy();
	return 0;
}
