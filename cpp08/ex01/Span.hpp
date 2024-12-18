#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>

class Span
{
private:
    unsigned int _size;
    std::vector<int> _numbers;

    Span();
public:
    Span(unsigned int n);
    Span(const Span &copy);
    Span &operator=(const Span &assign);
    ~Span();

    void addNumber(int n);
    int shortestSpan();
    int longestSpan();

    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif