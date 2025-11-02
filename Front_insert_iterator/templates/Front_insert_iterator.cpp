#ifndef __Front_insert_iterator_CPP__
#define __Front_insert_iterator_CPP__

#include "../headers/Front_insert_iterator.hpp"

template <typename FrontInsertSequence>
Front_insert_iterator<FrontInsertSequence>::Front_insert_iterator(FrontInsertSequence& x)
    : container_(&x)
{}

template <typename FrontInsertSequence>
Front_insert_iterator<FrontInsertSequence>::Front_insert_iterator(const Front_insert_iterator<FrontInsertSequence>& rhv)
    : container_(rhv.container_)
{}


template <typename FrontInsertSequence>
Front_insert_iterator<FrontInsertSequence>&
Front_insert_iterator<FrontInsertSequence>::operator*()
{
    return *this;
}

template <typename FrontInsertSequence>
Front_insert_iterator<FrontInsertSequence>& 
Front_insert_iterator<FrontInsertSequence>::operator=(const Front_insert_iterator<FrontInsertSequence>& rhv)
{
    if (this != &rhv) {
        container_ = rhv.container_;
    }
    return *this;
}

template <typename FrontInsertSequence>
Front_insert_iterator<FrontInsertSequence>&
Front_insert_iterator<FrontInsertSequence>::operator=(const typename FrontInsertSequence::value_type& value)
{
    container_->push_front(value);
    return *this;
}

template <typename FrontInsertSequence>
Front_insert_iterator<FrontInsertSequence>&
Front_insert_iterator<FrontInsertSequence>::operator++()
{
    return *this;
}

template <typename FrontInsertSequence>
Front_insert_iterator<FrontInsertSequence>&
Front_insert_iterator<FrontInsertSequence>::operator++(int)
{
    return *this;
}

#endif /// __Front_insert_iterator_CPP__

