#pragma once

#include <deque>
#include <utility>
#include <cstddef>

typedef struct PmergeMe PmergeMe_t;


class ft_deque
{
    private:
    public:
        ft_deque();
        std::deque<int> unsorted;
        std::deque<std::pair<int, int> > pairs;
        std::deque<int> main_chain;
        std::deque<int> second_chain;
        

        void    create_pairs();
        void    sort_pairs_swap();
        void    create_two_groups();
        void    insert();


        ft_deque(PmergeMe_t &pmergeme);
        ft_deque(const ft_deque &other);
        ft_deque &operator=(const ft_deque &other);
        ~ft_deque();
};

void   ft_merge_sort(std::deque<std::pair<int, int> > &, size_t, size_t);