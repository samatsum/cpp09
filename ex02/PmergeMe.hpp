/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <schahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:35:20 by schahid           #+#    #+#             */
/*   Updated: 2023/05/14 09:35:20 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <cstring>
# include <cstdlib>
# include <time.h>
# include <iomanip>

class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int> deq;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& copy);
        PmergeMe& operator=(const PmergeMe& in);
        void checkConvert(int argc, char **argv);
        void mergeInsertVec(int start, int end);
        void InsertVec(int start, int end);
        void mergeVec(int start, int mid, int end);
        bool isDuplicateVec();
        void printOut(int argc, char **argv, double dur_vec, double dur_deq);
        void mergeInsertDeq(int start, int end);
        void InsertDeq(int start, int end);
        void mergeDeq(int start, int mid, int end);
        bool isDuplicateDeq();
        double deq_duration();
        double vec_duration();
};

#endif
