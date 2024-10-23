#include "ft_list.hpp"
#include "PmergeMe.hpp"





std::list<int> merge_insert_with_list(PmergeMe_t &pmergeme){
    ft_list list(pmergeme);

    list.create_pairs();
    list.sort_pairs();
    list.create_two_groups();
    list.sort_small_group();
    list.insert_large_in_small_in_the_right_pos();


    return list.main_chain;
}

ft_list::ft_list(PmergeMe_t &pmergeme){
    for (int i = 0; i < pmergeme.size; i++){
        unsorted.push_back(pmergeme.arr[i]);
    }
}



void ft_list::create_pairs(){
    for ( std::list<int>::iterator it = unsorted.begin(); it != unsorted.end(); it++)
    {
        int a = *it;
        int b = (++it == unsorted.end() ? -1 : *it);
        pairs.push_back(std::pair<int, int>(a, b));
        if (b == -1)
            return ;
    }
}

void ft_list::sort_pairs(){
    std::list<std::pair<int, int> >::iterator it = pairs.begin();
    for (; it != pairs.end(); it++)
    {
        if (it->first > it->second && it->second != -1){
            std::swap(it->first, it->second);
        }
    }
}

void ft_list::create_two_groups(){
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        main_chain.push_back(it->first);
        if (it->second != -1)
            second_chain.push_back(it->second);
    }
}

void ft_list::sort_small_group(){
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
    for (std::list<int>::iterator it = main_chain.begin(); it != main_chain.end(); it++)
    {
        small_gr.arr[i] = *it;
        i++;
    }
    main_chain = merge_insert_with_list(small_gr);
    delete[] small_gr.arr;
    // main_chain = sorted_list;
}

std::list<int>::iterator get_element_by_index(std::list<int> &lst, int index) {
    if (index < 0 || index >= lst.size()) {
        throw std::out_of_range("Index out of range");
    }
    // std::cout << "Index: " << index << std::endl;
    std::list<int>::iterator it = lst.begin();
    std::advance(it, index);
    return it;
}


void    binary_insertation(std::list<int> &lst, int n, int start, int end){
    int mid = start + (end - start) / 2;
    std::list<int>::iterator it = get_element_by_index(lst, mid);

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

void    ft_list::insert_large_in_small_in_the_right_pos(){
    while (second_chain.size())
    {
        binary_insertation(main_chain, second_chain.front(), 0, main_chain.size() - 1);
        second_chain.pop_front();
    }
}


ft_list::ft_list()
{
}

ft_list::ft_list(const ft_list &other)
{
}

ft_list &ft_list::operator=(const ft_list &other)
{
    if (this != &other)
    {
    }
    return *this;
}

ft_list::~ft_list()
{
}

