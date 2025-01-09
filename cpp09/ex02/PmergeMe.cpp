#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av) {
    parseInput(ac, av);
    vector = vecInput;
    deque = std::deque<int>(vecInput.begin(), vecInput.end());
}

void PmergeMe::run() {
    printBefore();
    long vecStart = getTimeMs();
    fordJohnson(vector);
    long vecEnd = getTimeMs();
    long deqStart = getTimeMs();
    fordJohnson(deque);
    long deqEnd = getTimeMs();
    printAfter();
    std::cout << "Time to process a range of " << vector.size() << " elements with std::vector: " << (vecEnd - vecStart) << " us" << std::endl;
    std::cout << "Time to process a range of " << deque.size() << " elements with std::deque: " << (deqEnd - deqStart) << " us" << std::endl;
}

void PmergeMe::parseInput(int ac, char **av) {
    if (ac < 2)
        throw std::runtime_error("Not enough arguments");
    for (int i = 1; i < ac; i++) {
        std::string arg(av[i]);
        if (!isPositive(arg))
            throw std::runtime_error("Invalid argument");
        vecInput.push_back(std::atoi(arg.c_str()));
    }
}

void PmergeMe::printBefore(void) {
    std::cout << "Before:" << std::endl;
    printSequence(this->vecInput);
}

void PmergeMe::printAfter(void) {
    std::cout << "After:" << std::endl;
    printSequence(this->vector);
}

bool PmergeMe::isPositive(const std::string &str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    if (str.empty())
        return false;
    long value = std::atol(str.c_str());
    if (value <= 0 || value > std::numeric_limits<int>::max())
        return false;
    return true;
}

long PmergeMe::getTimeMs(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + tv.tv_usec;
}