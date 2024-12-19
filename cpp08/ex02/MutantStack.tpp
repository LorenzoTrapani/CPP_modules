#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<int>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<int>(other) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
	if (this != &other)
		std::stack<int>::operator=(other);
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return std::stack<int>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return std::stack<int>::c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
	return std::stack<int>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
	return std::stack<int>::c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
	return std::stack<int>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
	return std::stack<int>::c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {
	return std::stack<int>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {
	return std::stack<int>::c.rend();
}
