#pragma once

#include <list>
#include <utility>

typedef struct PmergeMe PmergeMe_t;


class ft_list
{
    private:
    public:
        std::list<int> unsorted;
        std::list<std::pair<int, int> > pairs;
        std::list<int> main_chain;
        std::list<int> second_chain;
        ft_list();


        // algo
        void    create_pairs();
        void    sort_pairs();
        void    create_two_groups();
        void    sort_small_group();
        void    insert_large_in_small_in_the_right_pos();

        ft_list(PmergeMe_t &pmergeme);
        ft_list(const ft_list &other);
        ft_list &operator=(const ft_list &other);
        ~ft_list();
};

