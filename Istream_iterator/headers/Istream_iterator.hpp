#ifndef __ISTREAM_ITERATOR_HPP__
#define __ISTREAM_ITERATOR_HPP__

#include <cstddef>
#include <iostream>
#include <iterator>

template <typename T, typename Distance = std::ptrdiff_t>
class Istream_iterator
{
public:
    typedef T value_type;
    typedef const T& reference;
    typedef const T* pointer;
    typedef Distance difference_type;
    typedef Distance distance_type;
    typedef std::input_iterator_tag iterator_category;

public:
    Istream_iterator(); 
    Istream_iterator(std::istream& stream); 	
    Istream_iterator(const Istream_iterator<T, Distance>& rhv); 
    Istream_iterator<T, Distance>& operator=(const Istream_iterator<T, Distance>& rhv);
    reference operator*() const;
    pointer operator->()  const;
    Istream_iterator<T, Distance>& operator++(); 
    Istream_iterator<T, Distance> operator++(int);
    bool operator==(const Istream_iterator<T, Distance>& rhv) const; 
    bool operator!=(const Istream_iterator<T, Distance>& rhv) const; 

private:
    std::istream* stream_;
    T current_;
};

#include "../templates/Istream_iterator.cpp"

template <typename T, typename Distance>
std::input_iterator_tag
iterator_category(const Istream_iterator<T, Distance>&)
{
    return std::input_iterator_tag();
}

template <typename T, typename Distance>
T*
value_type(const Istream_iterator<T, Distance>&)
{ 
    return NULL;
}

template <typename T, typename Distance>
Distance*
distance_type(const Istream_iterator<T, Distance>&)
{
    return NULL;
}

#endif /// __ISTREAM_ITERATOR_HPP__

