#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class RPN
{
    private:
        std::stack<int> _stack;
        void calculate(char op);
    public:
        RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &assign);
        ~RPN();
        void handleInput(const std::string &str);
};

#endif