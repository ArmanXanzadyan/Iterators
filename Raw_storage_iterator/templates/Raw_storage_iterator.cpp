#ifndef __Raw_storage_iterator_CPP__
#define __Raw_storage_iterator_CPP__

#include "../headers/Raw_storage_iterator.hpp"

template <typename ForwardIterator, typename T>
Raw_storage_iterator<ForwardIterator, T>::Raw_storage_iterator(ForwardIterator iterator)
    : iterator_(iterator)
{}

template <typename ForwardIterator, typename T>
Raw_storage_iterator<ForwardIterator, T>::Raw_storage_iterator(const Raw_storage_iterator<ForwardIterator, T>& rhv)
    : iterator_(rhv.iterator_)
{}

template <typename ForwardIterator, typename T>
Raw_storage_iterator<ForwardIterator, T>&
Raw_storage_iterator<ForwardIterator, T>::operator=(const Raw_storage_iterator<ForwardIterator, T>& rhv)
{
    if (this != &rhv) {
        iterator_ = rhv.iterator_;
    }
    return *this;
}

template <typename ForwardIterator, typename T>
Raw_storage_iterator<ForwardIterator, T>&
Raw_storage_iterator<ForwardIterator, T>::operator=(const T& value)
{
    typedef typename std::iterator_traits<ForwardIterator>::value_type value_type_;
    new (static_cast<void*>(&*iterator_)) value_type_(value);
    return *this;
}

template <typename ForwardIterator, typename T>
Raw_storage_iterator<ForwardIterator, T>&
Raw_storage_iterator<ForwardIterator, T>::operator*()
{
    return *this;
}

template <typename ForwardIterator, typename T>
Raw_storage_iterator<ForwardIterator, T>&
Raw_storage_iterator<ForwardIterator, T>::operator++()
{
    ++iterator_;
    return *this;
}

template <typename ForwardIterator, typename T>
Raw_storage_iterator<ForwardIterator, T>
Raw_storage_iterator<ForwardIterator, T>::operator++(int)
{
    Raw_storage_iterator<ForwardIterator, T> temp(*this);
    ++iterator_;
    return temp;
}

template <typename ForwardIterator, typename T>
ForwardIterator
Raw_storage_iterator<ForwardIterator, T>::base() const
{
    return iterator_;
}

#endif /// __Raw_storage_iterator_CPP__

