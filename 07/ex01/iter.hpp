#pragma once
#include <iostream>
#include <cmath>

template <typename T1, typename T2>
void iter(T1 arr[], size_t size, void (*func)(T2)){
    for (size_t i = 0; i < size; i++)
    {
        func(arr[i]);
    }
}