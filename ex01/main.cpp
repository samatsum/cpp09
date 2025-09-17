/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <schahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 09:17:10 by schahid           #+#    #+#             */
/*   Updated: 2023/05/13 16:39:03 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
        std::cout << "Please enter a RPN expression" << std::endl;
    else if (argc > 2)
        std::cout << "too many arguments" << std::endl;
    else
    {
        RPN exp;
        exp.argvTostring(argv);
    }
}

