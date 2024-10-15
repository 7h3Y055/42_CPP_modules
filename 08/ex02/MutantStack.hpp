#include <iostream>
#include <algorithm>
#include <stack>
#include <list>
#include <vector>
#include <deque>

template <class T, typename CONTAINER = std::deque<T> >
class MutantStack : public std::stack<T, CONTAINER>
{
    public:

        MutantStack() {}
        MutantStack(const MutantStack& other) : std::stack<T, CONTAINER>(other) {}
        MutantStack& operator=(const MutantStack& other) {
            if (this != &other) {
                std::stack<T, CONTAINER>::operator=(other);
            }
            return *this;
        }
        ~MutantStack() {}


        typedef typename std::stack<T, CONTAINER>::container_type::iterator iterator;
        iterator begin(){ return this->c.begin(); }
        iterator end(){   return this->c.end();   }
};
