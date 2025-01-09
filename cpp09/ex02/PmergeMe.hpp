#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <sys/time.h>
#include <stdexcept>
#include <string>
#include <limits>

class PmergeMe
{
public:
    PmergeMe(int ac, char **av);
    void run();

private:
    std::vector<int> vecInput;
    std::vector<int> vector;
    std::deque<int> deque;

    void parseInput(int ac, char **av);
    void printBefore(void);
	void printAfter(void);
	static bool isPositive(const std::string &str);
	static long getTimeMs(void);

	template <typename T>
	void printSequence(const T &data);

    template <typename T>
    void binaryInsertionSort(T &data, int value);

    template <typename T>
    void fordJohnson(T &data);
};

#include "PmergeMe.tpp"

#endif