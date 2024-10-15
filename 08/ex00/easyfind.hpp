#pragma once

#include <iostream>
#include <algorithm>

template <typename T>
int easyfind(T first, int second){
    if (std::find(first.begin(), first.end(), second) != first.end())
        return second;
    else
        throw std::runtime_error("[!] Not Found.");
}



