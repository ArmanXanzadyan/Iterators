#ifndef __REVERSE_BIDIRECTIONAL_ITERATOR_HPP__
#define __REVERSE_BIDIRECTIONAL_ITERATOR_HPP__

#include <cstddef>
#include <iterator>

template <typename BidirectionalIterator, typename T, typename Reference = T&, typename Distance = std::ptrdiff_t>
class Reverse_bidirectional_iterator
{
public:
    typedef Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference, Distance> self;
    typedef BidirectionalIterator                                                         iterator_type;
    typedef T                                                                             value_type;
    typedef Distance                                                                      difference_type;
    typedef T*                                                                            pointer;
    typedef Reference                                                                     reference;

public:
    Reverse_bidirectional_iterator();
    explicit Reverse_bidirectional_iterator(iterator_type it);
    Reverse_bidirectional_iterator(const self& rhv);
    
    self& operator=(const self& rhv);
    iterator_type base()   const;
    Reference operator*()  const;
    self& operator++();
    self operator++(int);
    self& operator--();
    self operator--(int);
    bool operator==(const self& rhv) const; 
    bool operator!=(const self& rhv) const; 

private:
    iterator_type iterator_;
};

#include "../templates/Reverse_bidirectional_iterator.cpp"


template <typename BidirectionalIterator, typename T, typename Reference = T&, typename Distance = std::ptrdiff_t>
typename std::iterator_traits<BidirectionalIterator>::iterator_category
iterator_category(const Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference , Distance>&)
{
    return typename std::iterator_traits<BidirectionalIterator>::itaretor_category();
}

template <typename BidirectionalIterator, typename T, typename Reference = T&, typename Distance = std::ptrdiff_t>
T*
value_type(const Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference , Distance>&)
{
    return (T*)0;
}

template <typename BidirectionalIterator, typename T, typename Reference = T&, typename Distance = std::ptrdiff_t>
Distance*
distance_type(const Reverse_bidirectional_iterator<BidirectionalIterator, T, Reference , Distance>&)
{
    return (Distance*)0;
}

#endif /// __REVERSE_BIDIRECTIONAL_ITERATOR_HPP__

