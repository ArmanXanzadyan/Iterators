#ifndef __FUNCTION_HPP_
#define __FUNCTION_HPP_

#include <iostream>

template <typename ForwardIterator>
void print(ForwardIterator first, ForwardIterator last);

template <typename ForwardIterator, typename T>
void iota(ForwardIterator first, const ForwardIterator last, T value); 

#include "../templates/function.cpp"

#endif /// __FUNCTION_HPP_

