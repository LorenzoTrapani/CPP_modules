#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int n) : _size(n) {}

Span::Span(const Span &copy) {
    *this = copy;
}

Span &Span::operator=(const Span &assign)
{
    if (this != &assign) {
        _size = assign._size;
        _numbers = assign._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if (_numbers.size() < _size)
        _numbers.push_back(n);
    else
        throw std::out_of_range("Error: Span is full");
}

int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw std::out_of_range("Error: Not enough numbers");
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int min = sorted[1] - sorted[0];
    for (unsigned int i = 2; i < sorted.size(); i++) {
        if ((sorted[i] - sorted[i - 1]) < min)
            min = sorted[i] - sorted[i - 1];
    }
    return min;
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw std::out_of_range("Error: Not enough numbers");
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    return sorted[sorted.size() - 1] - sorted[0];
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (_numbers.size() + std::distance(begin, end) > _size)
        throw std::out_of_range("Error: Span is full");
    _numbers.insert(_numbers.end(), begin, end);
}

