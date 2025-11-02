#ifndef __Back_inserter_iterator_CPP__
#define __Back_inserter_iterator_CPP__

#include "../headers/Back_inserter_iterator.hpp"

template <typename BackInsertionSequence>
Back_inserter_iterator<BackInsertionSequence>::Back_inserter_iterator(BackInsertionSequence& x)
    : container_(&x)
{}

template <typename BackInsertionSequence>
Back_inserter_iterator<BackInsertionSequence>::Back_inserter_iterator(const Back_inserter_iterator<BackInsertionSequence>& rhv)
    : container_(rhv.container_)
{}

template <typename BackInsertionSequence>
Back_inserter_iterator<BackInsertionSequence>&
Back_inserter_iterator<BackInsertionSequence>::operator*()
{
    return *this;
}

template <typename BackInsertionSequence>
Back_inserter_iterator<BackInsertionSequence>& 
Back_inserter_iterator<BackInsertionSequence>::operator=(const Back_inserter_iterator<BackInsertionSequence>& rhv)
{
    if (this != &rhv) {
        container_ = rhv.container_;
    }
    return *this;
}

template <typename BackInsertionSequence>
Back_inserter_iterator<BackInsertionSequence>&
Back_inserter_iterator<BackInsertionSequence>::operator=(const typename BackInsertionSequence::value_type& value)
{
    container_->push_back(value);
    return *this;
}

template <typename BackInsertionSequence>
Back_inserter_iterator<BackInsertionSequence>&
Back_inserter_iterator<BackInsertionSequence>::operator++()
{
    return *this;
}

template <typename BackInsertionSequence>
Back_inserter_iterator<BackInsertionSequence>&
Back_inserter_iterator<BackInsertionSequence>::operator++(int)
{
    return *this;
}

#endif /// __Back_inserter_iterator_CPP__

