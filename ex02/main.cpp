/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <schahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:35:24 by schahid           #+#    #+#             */
/*   Updated: 2023/05/14 09:35:24 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc != 1)
    {
        PmergeMe p;
        p.checkConvert(argc, argv);
    }
    else
        std::cout << "Please enter an argument" << std::endl;
}