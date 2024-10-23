#include "ft_deque.hpp"
#include "PmergeMe.hpp"


std::deque<int> merge_insert_with_deque(PmergeMe_t &pmergeme){
    ft_deque lst(pmergeme);

    lst.create_pairs();
    lst.sort_pairs();
    lst.create_two_groups();
    lst.sort_small_group();
    lst.insert_large_in_small_in_the_right_pos();

    return lst.main_chain;
}



void    ft_deque::create_pairs(){
    for (std::deque<int>::iterator it = unsorted.begin(); it != unsorted.end(); it++)
    {
        int a = *it;
        int b = (++it == unsorted.end() ? -1 : *it);
        pairs.push_back(std::pair<int, int>(a, b));
        if (b == -1)
            return ;
    }
}

void    ft_deque::sort_pairs(){
    for ( std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
        if (it->first > it->second && it->second != -1)
            std::swap(it->first, it->second);
}

void    ft_deque::create_two_groups(){
    for ( std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++){
        main_chain.push_back(it->first);
        if (it->second != -1)
            second_chain.push_back(it->second);
    }
}

void    ft_deque::sort_small_group(){
    if (main_chain.size() < 2)
        return ;
    else if (main_chain.size() == 2)
    {
        if (main_chain.front() > main_chain.back())
            std::iter_swap(main_chain.begin(), ++main_chain.begin());
        return ;
    }

    PmergeMe_t small_gr;
    small_gr.size = main_chain.size();
    small_gr.arr = new int[small_gr.size];

    int i = 0;
    for (std::deque<int>::iterator it = main_chain.begin(); it != main_chain.end(); it++)
    {
        small_gr.arr[i] = *it;
        i++;
    }
    main_chain = merge_insert_with_deque(small_gr);
    delete[] small_gr.arr;
}

std::deque<int>::iterator get_element_by_index(std::deque<int> &lst, int index) {
    if (index < 0 || index >= lst.size()) {
        throw std::out_of_range("Index out of range");
    }
    std::deque<int>::iterator it = lst.begin();
    std::advance(it, index);
    return it;
}

void    binary_insertation(std::deque<int> &lst, int n, int start, int end){
    int mid = start + (end - start) / 2;
    std::deque<int>::iterator it = get_element_by_index(lst, mid);

    if (start == end){
        if (*it > n)
            lst.insert(it, n);
        else
            lst.insert(++it, n);
    }else if (*it > n)
        binary_insertation(lst, n, start, mid);
    else
        binary_insertation(lst, n, mid + 1, end);
}


void    ft_deque::insert_large_in_small_in_the_right_pos(){
    while (second_chain.size())
    {
        binary_insertation(main_chain, second_chain.front(), 0, main_chain.size() - 1);
        second_chain.pop_front();
    }
}






ft_deque::ft_deque(PmergeMe_t &pmergeme){
    for (int i = 0; i < pmergeme.size; i++)
        unsorted.push_back(pmergeme.arr[i]);
}

ft_deque::ft_deque(){
}

ft_deque::ft_deque(const ft_deque &other){
}

ft_deque &ft_deque::operator=(const ft_deque &other){
    if (this != &other)
    {
    }
    return *this;
}

ft_deque::~ft_deque(){
}

