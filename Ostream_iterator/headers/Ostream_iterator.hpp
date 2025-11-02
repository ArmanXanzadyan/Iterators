#ifndef __OSTREAM_ITERATOR_HPP__
#define __OSTREAM_ITERATOR_HPP__

#include <iostream>
#include <iterator>

template <typename T>
class Ostream_iterator {
public:
    typedef std::output_iterator_tag iterator_category;
    typedef T                        value_type;
    typedef T&                       reference;
    typedef T*                       pointer;
    typedef std::ptrdiff_t           difference_type;

public:
    explicit Ostream_iterator(std::ostream& ostream1);
    Ostream_iterator(const Ostream_iterator<T>& rhv);
    Ostream_iterator(std::ostream& ostream1, const char* delimetr);
    Ostream_iterator<T>& operator=(const Ostream_iterator<T>& rhv);  
    Ostream_iterator<T>& operator=(const T& value);
    Ostream_iterator<T>& operator*();
    Ostream_iterator<T>& operator++();
    Ostream_iterator<T>& operator++(int); 

private:
    std::ostream* ostream_;
    const char* delimetr_;
};

#include "../templates/Ostream_iterator.cpp"

#endif /// OSTREAM_ITERATOR_HPP

