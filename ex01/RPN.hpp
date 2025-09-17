/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <schahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 09:17:27 by schahid           #+#    #+#             */
/*   Updated: 2023/05/13 16:37:05 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <cstdlib>
# include <cstring>
# include <stack>
# include <sstream>

class RPN
{
    private:
        std::stack<int> stack;
    public:
        RPN();
        ~RPN();
        RPN(const RPN& copy);
        RPN& operator=(const RPN& in);
        void argvTostring(char **argv);
        void expEval(std::string exp);
        int isOperand(char c);
        int isOperator(char c);
        int getStackTop();
        int calcOperation(int a, int b, char op);
};
#endif