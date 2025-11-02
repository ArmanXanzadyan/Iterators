
#ifndef __REVERSE_ITERATOR_CPP__
#define __REVERSE_ITERATOR_CPP__

#include "../headers/Reverse_bidirectional_iterator.hpp"

template <typename BidirectionalIterator, typename T, typename Reference, typename Distance>
Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference, Distance>::Reverse_bidirectional_iterator()
    : iterator_()
{}

template <typename BidirectionalIterator, typename T, typename Reference, typename Distance>
Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference, Distance>::Reverse_bidirectional_iterator(iterator_type it)
    : iterator_(it)
{}

template <typename BidirectionalIterator, typename T, typename Reference, typename Distance>
Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference, Distance>::Reverse_bidirectional_iterator(const self& rhv)
    : iterator_(rhv.iterator_)
{}

template <typename BidirectionalIterator, typename T, typename Reference, typename Distance>
typename Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference, Distance>::iterator_type
Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference, Distance>::base() const
{
    return iterator_;
}

template <typename RandomAccessIterator, typename T, typename Reference, typename Distance>
typename Reverse_bidirectional_iterator<RandomAccessIterator, T, Reference, Distance>::self&
Reverse_bidirectional_iterator<RandomAccessIterator, T, Reference, Distance>::operator=(const self& rhv)
{
    if (this != &rhv)
        iterator_ = rhv.iterator_;
    return *this;
}

template <typename BidirectionalIterator, typename T, typename Reference, typename Distance>
Reference
Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference, Distance>::operator*() const
{
    iterator_type temp = iterator_;
    return *(--temp);
}

template <typename BidirectionalIterator, typename T, typename Reference, typename Distance>
Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference, Distance>&
Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference, Distance>::operator++()
{
    --iterator_;
    return *this;
}

template <typename BidirectionalIterator, typename T, typename Reference, typename Distance>
Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference, Distance>
Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference, Distance>::operator++(int)
{
    Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference, Distance> temp = *this;
    --iterator_;
    return temp;
}

template <typename BidirectionalIterator, typename T, typename Reference, typename Distance>
Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference, Distance>&
Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference, Distance>::operator--()
{
    ++iterator_;
    return *this;
}

template <typename BidirectionalIterator, typename T, typename Reference, typename Distance>
Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference, Distance>
Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference, Distance>::operator--(int)
{
    Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference, Distance> temp = *this;
    ++iterator_;
    return temp;
}

template <typename BidirectionalIterator, typename T, typename Reference, typename Distance>
bool
Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference, Distance>::operator==(const self& rhv) const
{
    return iterator_ == rhv.iterator_;
}

template <typename BidirectionalIterator, typename T, typename Reference, typename Distance>
bool
Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference, Distance>::operator!=(const self& rhv) const
{
    return iterator_ != rhv.iterator_;
}

#endif /// __REVERSE_ITERATOR_CPP__

