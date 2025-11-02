#ifndef __REVERSE_ITERATOR_CPP__
#define __REVERSE_ITERATOR_CPP__

#include "../headers/Reverse_iterator.hpp"

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::Reverse_iterator()
    : iterator_()
{}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::Reverse_iterator(iterator_type it)
    : iterator_(it)
{}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::Reverse_iterator(const self& rhv)
    : iterator_(rhv.iterator_)
{}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
typename Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::iterator_type
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::base() const
{
    return iterator_;
}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
typename Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::self&
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::operator=(const self& rhv)
{
    if (this != &rhv)
        iterator_ = rhv.iterator_;
    return *this;
}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
typename Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::reference
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::operator*() const
{
    iterator_type temp = iterator_;
    return *(--temp);
}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
typename Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::pointer
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::operator->() const
{
    return &(operator*());
}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>&
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::operator++()
{
    --iterator_;
    return *this;
}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::operator++(int)
{
    Reverse_iterator<RandomAccessIterator, T, Reference, Distance> temp = *this;
    --iterator_;
    return temp;
}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>&
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::operator--()
{
    ++iterator_;
    return *this;
}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::operator--(int)
{
    Reverse_iterator<RandomAccessIterator, T, Reference, Distance> temp = *this;
    ++iterator_;
    return temp;
}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::operator+(const difference_type n) const
{
    return Reverse_iterator(iterator_ - n);
}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::operator-(const difference_type n) const
{
    return Reverse_iterator(iterator_ + n);
}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>&
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::operator+=(const difference_type n)
{
    iterator_ -= n;
    return *this;
}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>&
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::operator-=(const difference_type n)
{
    iterator_ += n;
    return *this;
}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
typename Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::reference
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::operator[](const difference_type n) const
{
    return *(*this + n);
}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
bool
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::operator==(const self& rhv) const
{
    return iterator_ == rhv.iterator_;
}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
bool
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::operator!=(const self& rhv) const
{
    return iterator_ != rhv.iterator_;
}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
bool
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::operator<(const self& rhv) const
{
    return iterator_ < rhv.iterator_;
}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
bool
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::operator>(const self& rhv) const
{
    return iterator_ > rhv.iterator_;
}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
bool
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::operator<=(const self& rhv) const
{
    return iterator_ <= rhv.iterator_;
}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
bool
Reverse_iterator<RandomAccessIterator, T, Reference, Distance>::operator>=(const self& rhv) const
{
    return iterator_ >= rhv.iterator_;
}

#endif /// __REVERSE_ITERATOR_CPP__

