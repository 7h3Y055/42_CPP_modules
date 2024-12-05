#pragma once

#include <list>
#include <utility>
#include <cstddef>

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
        void    sort_pairs_swap();
        //      ft_merge_sort
        void    create_two_groups();
        void    insert();

        ft_list(PmergeMe_t &pmergeme);
        ft_list(const ft_list &other);
        ft_list &operator=(const ft_list &other);
        ~ft_list();
};

void   ft_merge_sort(std::list<std::pair<int, int> > &, size_t, size_t);