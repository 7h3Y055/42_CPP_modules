#pragma once

#include <deque>
#include <utility>

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
        void    sort_pairs();
        void    create_two_groups();
        void    sort_small_group();
        void    insert_large_in_small_in_the_right_pos();


        ft_deque(PmergeMe_t &pmergeme);
        ft_deque(const ft_deque &other);
        ft_deque &operator=(const ft_deque &other);
        ~ft_deque();
};

