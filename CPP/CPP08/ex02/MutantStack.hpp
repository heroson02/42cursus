#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack
{
private:
    
public:
    MutantStack(/* args */);
    ~MutantStack();
    MutantStack(const MutantStack &obj);
    MutantStack& operator=(const MutantStack &obj);
};

#endif