#include "RPN.hpp"

RPN::RPN()
{

}

RPN::~RPN()
{

}

RPN::RPN(RPN const& copy)
{
    *this = copy;
}

RPN& RPN::operator=(RPN const& copy)
{
    (void) copy;
    return *this;
}

int RPN::operation(int num1, int num2, std::string const& oper)
{
    if (oper == "+")
        return num1 + num2;
    else if (oper == "-")
        return num1 - num2;
    else if (oper == "*")
        return num1 * num2;
    else if (oper == "/")
    {
        if (num2 != 0)
            return num1 / num2;
        else
            throw operationZero();
    }
    else
        throw invalidOperator();
}

int RPN::result(std::string const& expression)
{
    std::istringstream iss(expression);
    std::string token;
    while(iss >> token)
    {
        if (std::isdigit(token[0]))
            pile.push(std::atoi(token.c_str()));
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (pile.size() < 2)
                throw invalidExpression();
            else
            {
                int num2 = pile.top();
                pile.pop();
                int num1 = pile.top();
                pile.pop();
                int result = operation(num1, num2, token);
                pile.push(result);
            }
        }
        else
            throw invalidOperator();
    }
    if (pile.size() == 1)
        return pile.top();
    else
        throw invalidExpression();
}