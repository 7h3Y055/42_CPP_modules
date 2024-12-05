#include "ft_list.hpp"
#include "PmergeMe.hpp"

std::list<int> merge_insert_with_list(PmergeMe_t &pmergeme){
    ft_list list(pmergeme);

    list.create_pairs();
    list.sort_pairs_swap();
    ft_merge_sort(list.pairs, 0, list.pairs.size());
    list.create_two_groups();
    list.insert();

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

void ft_list::sort_pairs_swap(){
    std::list<std::pair<int, int> >::iterator it = pairs.begin();
    for (; it != pairs.end(); it++)
    {
        if (it->first < it->second && it->second != -1){
            std::swap(it->first, it->second);
        }
    }
}

void   ft_merge_sort(std::list<std::pair<int, int> > &list, size_t start, size_t end){
    std::list<std::pair<int, int> > sorted_list;
    std::list<std::pair<int, int> >::iterator it = list.begin();

    if (end - start < 2)
        return;
    size_t mid = start + ((end - start) / 2);
    ft_merge_sort(list, start, mid);
    ft_merge_sort(list, mid, end);

    // create a copy of the two groups
    std::list<std::pair<int, int> > L;
    std::list<std::pair<int, int> > R;
    for (size_t i = start; i < mid; i++) {
        it = list.begin();
        std::advance(it, i);
        L.push_back(std::make_pair(it->first, it->second));
    }
    for (size_t i = mid; i < end; i++) {
        it = list.begin();
        std::advance(it, i);
        R.push_back(std::make_pair(it->first, it->second));
    }

    size_t k = start;

    // merge the two groups
    while (L.size() && R.size()) {
        it = list.begin();
        std::advance(it, k);
        if (L.front().first < R.front().first) {
            *it = L.front();
            L.pop_front();
        } else {
            *it = R.front();
            R.pop_front();
        }
        k++;
    }

    // merge the remaining elements
    while (L.size()) {
        it = list.begin();
        std::advance(it, k);
        *it = L.front();
        L.pop_front();
        k++;
    }
    while (R.size()) {
        it = list.begin();
        std::advance(it, k);
        *it = R.front();
        R.pop_front();
        k++;
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

std::list<int> generate_Jacobsthal_list(size_t size){
    std::list<int> arr;
    size_t n2 = 0; // J_(n-2)
    size_t n1 = 1; // J_(n-1)
    while (n1 - 1 < size){
        arr.push_back(n1 + 2 * n2); //  J_n=J_(n-1)+2*J_(n-2). 
        n2 = n1;
        n1 = arr.back();
        for (size_t j = n1 - 1; j > n2 ; j--)
            arr.push_back(j);
    }
    return arr;
}

void    ft_list::insert(){
    std::list<int> jacobsthal = generate_Jacobsthal_list(second_chain.size());
    for (std::list<int>::iterator it = jacobsthal.begin(); it != jacobsthal.end(); it++)
    {
        try{
            binary_insertation(main_chain, *get_element_by_index(second_chain, *it - 1), 0, main_chain.size() - 1);
        }catch(...){}
    }
    // while (second_chain.size())
    // {
    //     binary_insertation(main_chain, second_chain.front(), 0, main_chain.size() - 1);
    //     second_chain.pop_front();
    // }
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

