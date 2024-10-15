#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>



class Span
{
    private:
        unsigned int size_n;
        std::vector<int> v;
    public:
        Span();
        Span(unsigned int);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();


        void    addNumber(int n);
        int     shortestSpan();
        int     longestSpan();
        
        template <typename T>
        void    addNumber(T begin, T end){
            if (std::distance(begin, end) + v.size() > size_n)
                throw std::runtime_error("[!] Span have no space.");
            v.insert(v.end(), begin, end);
        }
};




