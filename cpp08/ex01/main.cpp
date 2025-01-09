#include "Span.hpp"

int main()
{
	try {
    	Span sp = Span(5);
    	sp.addNumber(6);
    	sp.addNumber(3);
    	sp.addNumber(17);
    	sp.addNumber(9);
    	sp.addNumber(11);
    	std::cout << sp.shortestSpan() << std::endl;
    	std::cout << sp.longestSpan() << std::endl;

		sp.addNumber(1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
    	Span sp2 = Span(1000);
    	std::vector<int> v(1000, 0);
    	for (int i = 0; i < 1000; i++)
    	    v[i] = i;
    	sp2.addNumbers(v.begin(), v.end());
    	std::cout << sp2.shortestSpan() << std::endl;
    	std::cout << sp2.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
    return 0;
}