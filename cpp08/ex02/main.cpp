#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;

	std::cout << "TESTING MUTANTSTACK:" << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Element on top of the stack: " <<mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Stack size:" <<mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "\nTesting iterators:" << std::endl;
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

	std::cout << "\nTesting reverse iterators:" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	++rit;
	--rit;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	std::cout << "\nTESTING LIST:" << std::endl;
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << "Element on top of the list: " <<list.back() << std::endl;
	list.pop_back();
	std::cout << "List size:" <<list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::cout << "\nTesting iterators:" << std::endl;
	std::list<int>::iterator itl = list.begin();
	std::list<int>::iterator itle = list.end();
	++itl;
	--itl;
	while (itl != itle)
	{
		std::cout << *itl << std::endl;
		++itl;
	}
	return 0;
}