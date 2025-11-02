#ifndef __ISTREAM_ITERATOR_CPP__
#define __ISTREAM_ITERATOR_CPP__

#include "../headers/Istream_iterator.hpp"

template <typename T, typename Distance>
Istream_iterator<T, Distance>::Istream_iterator()
    : stream_(NULL)
{}

template <typename T, typename Distance>
Istream_iterator<T, Distance>::Istream_iterator(std::istream& stream)
    : stream_(&stream)
{
    ++(*this);
}

template <typename T, typename Distance>
Istream_iterator<T, Distance>::Istream_iterator(const Istream_iterator<T, Distance>& rhv)
    : stream_(rhv.stream_)
    , current_(rhv.current_)
{}

template <typename T, typename Distance>
Istream_iterator<T, Distance>&
Istream_iterator<T, Distance>::operator=(const Istream_iterator<T, Distance>& rhv)
{
    if (this != &rhv) {
        stream_ = rhv.stream_;
        current_ = rhv.current_;
    }
    return *this;
}


template <typename T, typename Distance>
typename Istream_iterator<T, Distance>::reference
Istream_iterator<T, Distance>::operator*() const
{
    return current_;
}

template <typename T, typename Distance>
typename Istream_iterator<T, Distance>::pointer
Istream_iterator<T, Distance>::operator->() const
{
    return &current_;
}

template <typename T, typename Distance>
Istream_iterator<T, Distance>&
Istream_iterator<T, Distance>::operator++()
{
    if (!(*stream_ >> current_)) {
        stream_ = NULL; 
    }
    return *this; 
}

template <typename T, typename Distance>
Istream_iterator<T, Distance>
Istream_iterator<T, Distance>::operator++(int)
{
    Istream_iterator<T, Distance> temp = *this;
    ++(*this);
    return temp;
}

template <typename T, typename Distance>
bool
Istream_iterator<T, Distance>::operator==(const Istream_iterator<T, Distance>& rhv) const
{
    return rhv.stream_ == stream_;
}

template <typename T, typename Distance>
bool
Istream_iterator<T, Distance>::operator!=(const Istream_iterator<T, Distance>& rhv) const
{
    return !(*this == rhv);
}

#endif /// __ISTREAM_ITERATOR_CPP__

