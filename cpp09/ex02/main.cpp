#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try {
        PmergeMe pmm(ac, av);
        pmm.run();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}