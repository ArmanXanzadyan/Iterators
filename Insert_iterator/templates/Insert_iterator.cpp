#ifndef __Insert_iterator_CPP__
#define __Insert_iterator_CPP__

#include "../headers/Insert_iterator.hpp"

template <typename Container>
Insert_iterator<Container>::Insert_iterator(Container& x, typename Container::iterator it)
    : container_(&x)
    , iterator_(it)
{}

template <typename Container>
Insert_iterator<Container>::Insert_iterator(const Insert_iterator<Container>& rhv)
    : container_(rhv.container_)
    , iterator_(rhv.iterator_)
{}

template <typename Container>
Insert_iterator<Container>&
Insert_iterator<Container>::operator*()
{
    return *this;
}

template <typename Container>
Insert_iterator<Container>& 
Insert_iterator<Container>::operator=(const Insert_iterator<Container>& rhv)
{
    if (this != &rhv) {
        container_ = rhv.container_;
        iterator_ = rhv.iterator_;
    }
    return *this;
}

template <typename Container>
Insert_iterator<Container>&
Insert_iterator<Container>::operator=(const typename Container::value_type& value)
{
    container_->insert(iterator_, value);
    ++iterator_;
    return *this;
}

template <typename Container>
Insert_iterator<Container>&
Insert_iterator<Container>::operator++()
{
    return *this;
}

template <typename Container>
Insert_iterator<Container>&
Insert_iterator<Container>::operator++(int)
{
    return *this;
}

#endif /// __Insert_iterator_CPP__

