#include "ft_deque.hpp"
#include "PmergeMe.hpp"


std::deque<int> merge_insert_with_deque(PmergeMe_t &pmergeme){
    ft_deque list(pmergeme);

    list.create_pairs();
    list.sort_pairs_swap();
    ft_merge_sort(list.pairs, 0, list.pairs.size());
    list.create_two_groups();
    list.insert();

    return list.main_chain;
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

void    ft_deque::sort_pairs_swap(){
    for ( std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
        if (it->first > it->second && it->second != -1)
            std::swap(it->first, it->second);
}

void   ft_merge_sort(std::deque<std::pair<int, int> > &deque, size_t start, size_t end){
    std::deque<std::pair<int, int> > sorted_deque;

    if (end - start < 2)
        return;
    size_t mid = start + ((end - start) / 2);
    ft_merge_sort(deque, start, mid);
    ft_merge_sort(deque, mid, end);

    // create a copy of the two groups
    std::deque<std::pair<int, int> > L;
    std::deque<std::pair<int, int> > R;
    for (size_t i = start; i < mid; i++)
        L.push_back(std::make_pair(deque[i].first, deque[i].second));
    for (size_t i = mid; i < end; i++)
        R.push_back(std::make_pair(deque[i].first, deque[i].second));

    size_t k = start;

    // merge the two groups
    while (L.size() && R.size()) {
        if (L.front().first < R.front().first) {
            deque[k] = L.front();
            L.pop_front();
        } else {
            deque[k] = R.front();
            R.pop_front();
        }
        k++;
    }

    // merge the remaining elements
    while (L.size()) {
        deque[k] = L.front();
        L.pop_front();
        k++;
    }
    while (R.size()) {
        deque[k] = R.front();
        R.pop_front();
        k++;
    }
}

void    ft_deque::create_two_groups(){
    for ( std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++){
        main_chain.push_back(it->first);
        if (it->second != -1)
            second_chain.push_back(it->second);
    }
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

std::deque<int> generate_Jacobsthal_deque(size_t size){
    std::deque<int> arr;
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

void    ft_deque::insert(){
    std::deque<int> jacobsthal = generate_Jacobsthal_deque(second_chain.size());
    for (std::deque<int>::iterator it = jacobsthal.begin(); it != jacobsthal.end(); it++)
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

