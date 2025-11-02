#ifndef __OSTREAM_ITERATOR_CPP__
#define __OSTREAM_ITERATOR_CPP__

#include "../headers/Ostream_iterator.hpp"
#include <ostream>

template <typename T>
Ostream_iterator<T>::Ostream_iterator(std::ostream& ostream1)
    : ostream_(&ostream1)
    , delimetr_(0)
{}

template <typename T>
Ostream_iterator<T>::Ostream_iterator(std::ostream& ostream1, const char* delimetr)
    : ostream_(&ostream1)
    , delimetr_(delimetr)
{}

template <typename T>
Ostream_iterator<T>&
Ostream_iterator<T>::operator=(const Ostream_iterator<T>& rhv)
{
    if (this != &rhv) {
        ostream_ = rhv.ostream_;
        delimetr_ = rhv.delimetr_;
    }
    return *this;
}

template <typename T>
Ostream_iterator<T>&
Ostream_iterator<T>::operator=(const T& value)
{
    *ostream_ << value;
    if (delimetr_ != NULL) {
        *ostream_ << delimetr_;
    }
    return *this;
}

template <typename T>
Ostream_iterator<T>&
Ostream_iterator<T>::operator*()
{ 
    return *this;
}

template <typename T>
Ostream_iterator<T>&
Ostream_iterator<T>::operator++()
{
    return *this;
}

template <typename T>
Ostream_iterator<T>&
Ostream_iterator<T>::operator++(int)
{
    return *this;
}

#endif /// OSTREAM_ITERATOR_CPP__

