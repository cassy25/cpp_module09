#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
#include <stdexcept>

class RPN
{
    public:
        RPN();
        ~RPN();
        RPN(RPN const& copy);
        RPN& operator=(RPN const& copy);
        int operation(int num1, int num2, std::string const& oper);
        int result(std::string const& expression);
        class invalidOperator : public std::exception
        {
            virtual const char* what() const throw()
            {    
                return "INVALID OPERATOR";
            }
        };
        class operationZero : public std::exception
        {
            virtual const char* what() const throw()
            {    
                return "OPERATION / 0 IMPOSSIBLE";
            }
        };
        class invalidExpression : public std::exception
        {
            virtual const char* what() const throw()
            {    
                return "INVALID EXPRESSION";
            }
        };
    private:
        std::stack<int> pile;
};

#endif