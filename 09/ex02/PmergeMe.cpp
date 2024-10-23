#include "PmergeMe.hpp"

void print_status(PmergeMe_t pmergeme){
    std::cout << "Before\t\t\t: ";
    for (int i = 0; i < pmergeme.size; i++)
        std::cout << pmergeme.arr[i] << " ";
    std::cout << std::endl;

    std::cout << "After (std::list)\t: ";
    for (std::list<int>::iterator it = pmergeme.sorted_list.begin(); it != pmergeme.sorted_list.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "After (std::deque)\t: ";
    for (std::list<int>::iterator it = pmergeme.sorted_list.begin(); it != pmergeme.sorted_list.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;


    double list_time = pmergeme.list_end_time - pmergeme.list_start_time;
    double deque_time = pmergeme.deque_end_time - pmergeme.deque_start_time;

    std::cout << std::fixed << std::setprecision(2) << "Time to process a range of " << pmergeme.size << " elements with std::list  : " << list_time << " us" << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "Time to process a range of " << pmergeme.size << " elements with std::deque : " << deque_time << " us" << std::endl;
}


void check_init(int argc, char *argv[], PmergeMe_t &pmergeme) {
    pmergeme.size = argc - 1;
    pmergeme.arr = new int[pmergeme.size];
    for (int i = 1; i < argc; i++)
    {
        if (std::strlen(argv[i]) > 11)
            throw std::invalid_argument("Invalid argument!");
        for (size_t j = 0; argv[i][j]; j++)
        {
            if (argv[i][j] == '+')
                j++;
            if (argv[i][j] && !std::isdigit(argv[i][j]))
                throw std::invalid_argument("Invalid argument!");
        }
        long n = std::atol(argv[i]);
        if (n > std::numeric_limits<int>::max())
            throw std::invalid_argument("Invalid argument!");
        pmergeme.arr[i - 1] = n;
    }
}

