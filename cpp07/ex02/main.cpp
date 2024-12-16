#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Array.hpp"

int main() 
{
    try {
        std::cout << "Empty array test:" << std::endl;
        Array<int> empty_arr;
        std::cout << "Empty_arr size: " << empty_arr.size() << std::endl;

        std::cout << "\nArray with 5 elements test:" << std::endl;
        Array<int> Original_arr(5);
        std::cout << "Original_arr size: " << Original_arr.size() << std::endl;
		for (unsigned int i = 0; i < Original_arr.size(); ++i) {
            Original_arr[i] = i;
        }
        for (unsigned int i = 0; i < Original_arr.size(); ++i) {
            std::cout << "Original_arr[" << i << "] = " << Original_arr[i] << std::endl;
        }

		std::cout << "\nCopy constructor test:" << std::endl;
		Array<int> Copy_arr = Original_arr;
        std::cout << "Copy_arr size: " << Copy_arr.size() << std::endl;
		std::cout << "Before a change" << std::endl;
		for (unsigned int i = 0; i < Copy_arr.size(); ++i) {
            std::cout << "Copy_arr[" << i << "] = " << Copy_arr[i] << std::endl;
        }
		Original_arr[0] = 42;
		std::cout << "After change" << std::endl;
		std::cout << "Original:" << std::endl;
		for (unsigned int i = 0; i < Original_arr.size(); ++i) {
            std::cout << "Original_arr[" << i << "] = " << Original_arr[i] << std::endl;
        }
		std::cout << "Copy:" << std::endl;
        for (unsigned int i = 0; i < Copy_arr.size(); ++i) {
            std::cout << "Copy_arr[" << i << "] = " << Copy_arr[i] << std::endl;
        }

		std::cout << "\nAssignment operator test:" << std::endl;
        Array<int> Assign_arr(3);
        Assign_arr = Original_arr;
        std::cout << "Assign_arr size: " << Assign_arr.size() << std::endl;
        for (unsigned int i = 0; i < Assign_arr.size(); ++i) {
            std::cout << "Assign_arr[" << i << "] = " << Assign_arr[i] << std::endl;
        }

		std::cout << "\nOut of range test:" << std::endl;
        std::cout << "Original_arr[10] = " << Original_arr[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}