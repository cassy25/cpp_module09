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
    return *this;
}

int RPN::operation(int num1, int num2, std::string const& oper)
{
    int result = 0;
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
    size_t i = 0;

    while(i < expression.length())
    {
        if (isspace(expression[i]))
        {
            i++;
            continue;
        }
        if (std::isdigit(expression[i]) || (expression[i] == '-' && std::isdigit(expression[i + 1])))
        {
            size_t j = i;
            while (j < expression.length() && (std::isdigit(expression[j]) || (expression[j] == '-')))
                j++;
            std::string numStr = expression.substr(i, j - 1);
            i = j;
            pile.push(std::stoi(numStr));
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
        {
            if (pile.size() < 2)
                throw invalidExpression();
        
            int num2 = pile.top();
            pile.pop();
            int num1 = pile.top();
            pile.pop();
            int result = operation(num1, num2, std::string(1, expression[i]));
            pile.push(result);
        }
        else
            throw invalidOperator();
    }
    if (pile.size() == 1)
        return pile.top();
    else
        throw invalidExpression();
}