#ifndef __FUNCTION_CPP_
#define __FUNCTION_CPP_

#include "../headers/function.hpp"

template <typename ForwardIterator>
void
print(ForwardIterator first, ForwardIterator last)
{
    for (; first != last; ++first) {
        std::cout << *first << ' ';
    }
    std::cout << std::endl;
}

template <typename ForwardIterator, typename T>
void 
iota(ForwardIterator first, const ForwardIterator last, T value) 
{
    while (first != last) {
        *first++ = value++;
    }
}

#endif /// __FUNCTION_CPP_

