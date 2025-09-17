/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <schahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 09:17:05 by schahid           #+#    #+#             */
/*   Updated: 2023/05/13 16:46:23 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN& copy)
{
    this->stack = copy.stack;
}

RPN& RPN::operator=(const RPN& in)
{
    this->stack = in.stack;
    return (*this);
}

int RPN::isOperand(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (-1);
}

int RPN::isOperator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*')
        return (1);
    return (-1); 
}

int RPN::calcOperation(int a, int b, char op)
{
    if (op == '+')
        return (b+a);
    else if (op == '-')
        return (b-a);
    else if (op == '/')
    {
        if (a == 0)
        {
            std::cout << "Error" << std::endl;
            exit(EXIT_FAILURE);
        }
        return (b/a);
    }
    else
        return (b*a);
}

int RPN::getStackTop()
{
    return (this->stack.top());
}

void RPN::argvTostring(char **argv)
{
    std::stringstream ss;
    std::string expression;
    int i = 1;
    int j = 0;

    while (argv[i])
    {
        while (argv[i][j])
        {
            ss << argv[i][j];
            j++;
        }
        i++;
    }
    expression = ss.str();
    expEval(expression);
}

void RPN::expEval(std::string exp)
{
    size_t i = 0;
    int res;

    while (i < exp.length())
    {
        while (isspace(exp[i]))
            i++;
        if (isOperand(exp[i]) != -1)
        {
            char tmp[2] = {exp[i], '\0'};
            this->stack.push(atoi(tmp));
        }
        else if (isOperator(exp[i]) != -1)
        {
            if (this->stack.size() < 2)
            {
                std::cout << "Error" << std::endl;
                exit(EXIT_FAILURE);
            }
            int a = this->stack.top();
            this->stack.pop();
            int b = this->stack.top();
            this->stack.pop();
            res = calcOperation(a, b, exp[i]);
            this->stack.push(res);
        }
        else
        {
            std::cout << "Error" << std::endl;
            exit(EXIT_FAILURE);
        }
        i++;
    }
    if (this->stack.size() != 1)
    {
        std::cout << "Error" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << getStackTop() << std::endl;
}


