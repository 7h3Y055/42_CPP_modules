#include "Span.hpp"



void    Span::addNumber(int n){
    if (v.size() == size_n)
        throw std::runtime_error("[!] Span have no space.");
    v.push_back(n);
}

int     Span::shortestSpan(){
    if (v.size() < 2)
        throw std::runtime_error("[!] Span have no enough numbers.");

    std::sort(v.begin(), v.end());
    int min = v[1] - v[0];
    for (unsigned int i = 0; i < v.size() - 1; i++)
        if (min > v[i + 1] - v[i])
            min = v[i + 1] - v[i];
    return min;
}

int     Span::longestSpan(){
    if (v.size() < 2)
        throw std::runtime_error("[!] Span have no enough numbers.");

    std::sort(v.begin(), v.end());
    return (v.back() - v.front());
}

Span::Span():size_n(0){
}

Span::Span(unsigned int n):size_n(n){
}

Span::Span(const Span& other):size_n(other.size_n), v(other.v){
}

Span& Span::operator=(const Span& other){
    if (this != &other)
    {
        this->size_n = other.size_n;
        this->v = other.v;
    }
    return *this;
}

Span::~Span()
{
}