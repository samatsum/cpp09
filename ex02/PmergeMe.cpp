/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahid <schahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:45:20 by schahid           #+#    #+#             */
/*   Updated: 2023/05/14 10:03:51 by schahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
    this->vec = copy.vec;
    this->deq = copy.deq;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& in)
{
    this->vec = in.vec;
    this->deq = in.deq;
    return (*this);
}

//vector

bool PmergeMe::isDuplicateVec()
{
    int size = this->vec.size();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (vec[i] == vec[j])
                return true;
        }
    }
    return false;
}

double PmergeMe::vec_duration()
{
    clock_t start = clock();
    mergeInsertVec(0, this->vec.size() - 1);
    clock_t end = clock();
    double dur = double(end - start) / CLOCKS_PER_SEC;
    return (dur);
}

void PmergeMe::mergeVec(int start, int mid, int end)
{
    int left_size = mid - start + 1;
    int right_size = end - mid;
    std::vector<int> left(left_size);
    std::vector<int> right(right_size);

    int i = 0;
    while (i < left_size)
    {
        left[i] = this->vec[start + i];
        i++;
    }
    int j = 0;
    while (j < right_size)
    {
        right[j] = this->vec[mid + 1 + j];
        j++;
    }
    i = 0;
    j = 0;
    int idx = start;
    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            this->vec[idx] = left[i];
            i++;
        }
        else
        {
            this->vec[idx] = right[j];
            j++;
        }
        idx++;
    }

    while (i < left_size)
    {
        this->vec[idx] = left[i];
        i++;
        idx++;
    }

    while (j < right_size)
    {
        this->vec[idx] = right[j];
        j++;
        idx++;
    }
}

void PmergeMe::InsertVec(int start, int end)
{
    for (int i = start+1; i <= end; i++)
    {
        int key = this->vec[i];
        int j = i - 1; 
        while (j >= start && this->vec[j] > key)
        {
            this->vec[j + 1] = this->vec[j];
            j--;
        }
        this->vec[j + 1] = key;
    }
}

void PmergeMe::mergeInsertVec(int start, int end)
{
    if (start < end)
    {
        if (end - start <= 10)
            InsertVec(start, end);
        else
        {
            int mid = start + (end - start) / 2;
            mergeInsertVec(start, mid);
            mergeInsertVec(mid+1, end);
            mergeVec(start, mid, end);
        }
    }
}

void PmergeMe::printOut(int argc, char **argv, double dur_vec, double dur_deq)
{
    if (isDuplicateVec())
    {
        std::cerr << "Error: a duplicate has been detected, check your arguments." << std::endl;
        exit(EXIT_FAILURE);
    }
    if (isDuplicateDeq())
    {
        std::cerr << "Error: a duplicate has been detected, check your arguments." << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Before: " ;
    for (int i = 1; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << std::endl;
    std::cout << "After: " ;
    for (size_t j = 0; j < this->vec.size(); j++)
        std::cout << this->vec[j] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << argc - 1 
    << " elements with std::this->vector : ";
    std::printf("%.6fs", dur_vec);
    std::cout << std::endl;
    std::cout << "Time to process a range of " << argc - 1 
    << " elements with std::this->deque : ";
    std::printf("%.6fs", dur_deq);
    std::cout << std::endl;
}

void PmergeMe::checkConvert(int argc, char **argv)
{
    int i = 1;
    int j = 0;
    while (argv[i])
    {
        while (argv[i][j])
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
            {
                std::cerr << "Error: please enter a valid argument." << std::endl;
                exit(EXIT_FAILURE);
            }
            j++;
        }
        j = 0;
        i++;
    }
    i = 1;
    while(i < argc)
    {
        this->vec.push_back(atoi(argv[i]));
        this->deq.push_back(atoi(argv[i]));
        i++;
    }
    printOut(argc, argv, vec_duration(), deq_duration());
}

//deque


double PmergeMe::deq_duration()
{
    clock_t start = clock();
    mergeInsertDeq(0, this->deq.size() - 1);
    clock_t end = clock();
    double dur = double(end - start) / CLOCKS_PER_SEC;
    return (dur);
}

bool PmergeMe::isDuplicateDeq()
{
    int size = this->deq.size();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (deq[i] == deq[j])
                return true;
        }
    }
    return false;
}

void PmergeMe::mergeDeq(int start, int mid, int end)
{
    int left_size = mid - start + 1;
    int right_size = end - mid;
    std::deque<int> left(left_size);
    std::deque<int> right(right_size);

    int i = 0;
    while (i < left_size)
    {
        left[i] = this->deq[start + i];
        i++;
    }
    int j = 0;
    while (j < right_size)
    {
        right[j] = this->deq[mid + 1 + j];
        j++;
    }
    i = 0;
    j = 0;
    int idx = start;
    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            this->deq[idx] = left[i];
            i++;
        }
        else
        {
            this->deq[idx] = right[j];
            j++;
        }
        idx++;
    }

    while (i < left_size)
    {
        this->deq[idx] = left[i];
        i++;
        idx++;
    }

    while (j < right_size)
    {
        this->deq[idx] = right[j];
        j++;
        idx++;
    }
}

void PmergeMe::InsertDeq(int start, int end)
{
    for (int i = start+1; i <= end; i++)
    {
        int key = this->deq[i];
        int j = i -1;
        while (j >= start && this->deq[j] > key)
        {
            this->deq[j + 1] = this->deq[j];
            j--;
        }
        this->deq[j + 1] = key;
    }
}

void PmergeMe::mergeInsertDeq(int start, int end)
{
    if (start < end)
    {
        if (end - start <= 10)
            InsertDeq(start, end);
        else
        {
            int mid = start + (end - start) / 2;
            mergeInsertDeq(start, mid);
            mergeInsertDeq(mid+1, end);
            mergeDeq(start, mid, end);
        }
    }
}