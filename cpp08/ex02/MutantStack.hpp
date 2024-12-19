#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<int>
{
public:
	MutantStack();
	MutantStack(const MutantStack &copy);
	~MutantStack();
	MutantStack &operator=(const MutantStack &assign);

	typedef typename std::stack<int>::container_type::iterator iterator;
	typedef typename std::stack<int>::container_type::const_iterator const_iterator;
	typedef typename std::stack<int>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<int>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif