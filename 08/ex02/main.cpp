#include "MutantStack.hpp"


void test1()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}


void print_stack(MutantStack<char, std::vector<char> > &c){
    std::cout << "\t ___ " << std::endl;
    std::cout << "\t|TOP|" << std::endl;
    std::cout << "\t|" << "---" << "|" << std::endl;
    for (MutantStack<char, std::vector<char> >::iterator it = c.end() - 1; it !=  c.begin() - 1; it--)
    {
        std::cout << "\t| " << *it << " |" << std::endl;
        std::cout << "\t|" << "---" << "|" << std::endl;
    }
    std::cout << "\t|BTM|" << std::endl;
    std::cout << "\t ⎻⎻⎻ " << std::endl;
}

void test2()
{
    MutantStack<char, std::vector<char> > c;

    std::cout << "[⚙️] Is empty: " << c.empty() << std::endl;

    c.push('a');
    c.push('b');
    c.push('c');
    c.push('d');
    c.push('e');
    
    print_stack(c);
    std::cout << "[⚙️] Size: " << c.size() << std::endl;
    std::cout << "[⚙️] pop element \'" << c.top() << "\'" << std::endl;
    c.pop();
    print_stack(c);
    std::cout << "[⚙️] Size: " << c.size() << std::endl;
    std::cout << "[⚙️] Reverse container."<< std::endl;
    std::reverse(c.begin(), c.end());
    MutantStack<char, std::vector<char> > c2(c);
    print_stack(c2);
    std::cout << "[⚙️] Is empty: " << c2.empty() << std::endl;
}


void test3()
{
    MutantStack<std::string, std::list<std::string> > list;

    list.push("ONE");
    list.push("TWO");
    list.push("THREE");
    list.push("FOUR");
    list.push("FIVE");

    MutantStack<std::string, std::list<std::string> >::iterator it = list.begin();
    for (; it != list.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "----------------" << std::endl;
    MutantStack<std::string, std::list<std::string> >::iterator five;
    five = std::find(list.begin(), list.end(), "SIX");
    if (five != list.end())
        std::cout << "[+] Founded!" << std::endl;
    else
        std::cout << "[-] Not Found!" << std::endl;
}



int main()
{
    test1();
    // test2();
    // test3();
    return 0;
}

