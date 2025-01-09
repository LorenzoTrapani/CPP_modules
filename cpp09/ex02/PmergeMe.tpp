#include "PmergeMe.hpp"

template <typename T>
    void PmergeMe::printSequence(const T &data)
    {
        size_t size = data.size();
        if (size <= 20) {
            for (size_t i = 0; i < size; i++) {
                std::cout << data[i];
                std::cout << (i + 1 < size ? " " : "\n");
            }
        } else {
            for (size_t i = 0; i < 10; i++)
                std::cout << data[i] << " ";
            std::cout << "... ";
            for (size_t i = size - 10; i < size; i++)
                std::cout << data[i] << (i + 1 < size ? " " : "\n");
        }
    }

    template <typename T>
    void PmergeMe::binaryInsertionSort(T &data, int value)
    {
        typename T::iterator it = std::lower_bound(data.begin(), data.end(), value);
        data.insert(it, value);
    }

    template <typename T>
    void PmergeMe::fordJohnson(T &data)
    {
        if (data.size() < 2)
            return;
        T firstPair;
        T secondPair;
        typename T::iterator it = data.begin();
        while (it != data.end()) {
            int first = *it++;
            if (it != data.end()) {
                int second = *it++;
                if (first > second) {
                    int tmp = first;
                    first = second;
                    second = tmp;
                }
                firstPair.push_back(first);
                secondPair.push_back(second);
            } else
                firstPair.push_back(first);
        }
        std::sort(firstPair.begin(), firstPair.end());
        for (typename T::iterator it = secondPair.begin(); it != secondPair.end(); ++it) {
            binaryInsertionSort(firstPair, *it);
        }
        data = firstPair;
    }