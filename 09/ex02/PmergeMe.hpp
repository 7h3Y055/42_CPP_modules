#pragma once


#include <iostream>
#include <exception>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <ctime>
#include <iomanip>

#include "ft_deque.hpp"
#include "ft_list.hpp"


typedef struct PmergeMe
{
    int size;
    int *arr;
    std::list<int> sorted_list;
    std::deque<int> sorted_deque;
    double list_start_time;
    double list_end_time;
    double deque_start_time;
    double deque_end_time;

} PmergeMe_t;


void check_init(int argc, char *argv[], PmergeMe_t &pmergeMe);
std::deque<int> merge_insert_with_deque(PmergeMe_t &pmergeme);
std::list<int> merge_insert_with_list(PmergeMe_t &pmergeme);
void print_status(PmergeMe_t pmergeme);
