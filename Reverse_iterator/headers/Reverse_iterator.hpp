#ifndef __REVERSE_ITERATOR_HPP__
#define __REVERSE_ITERATOR_HPP__

#include <cstddef>
#include <iterator>

template <typename RandomAccessIterator, typename T, typename Reference = T&, typename Distance = std::ptrdiff_t>
class Reverse_iterator
{
public:
    typedef Reverse_iterator<RandomAccessIterator, T, Reference, Distance> self;
    typedef RandomAccessIterator                                           iterator_type;
    typedef T                                                              value_type;
    typedef Distance                                                       difference_type;
    typedef T*                                                             pointer;
    typedef Reference                                                      reference;

public:
    Reverse_iterator();
    explicit Reverse_iterator(iterator_type it);
    Reverse_iterator(const self& rhv);

    self& operator=(const self& rhv);
    iterator_type base()   const;
    reference operator*()  const;
    pointer   operator->() const;
    self& operator++();
    self operator++(int);
    self& operator--();
    self operator--(int);
    self operator+(const difference_type n) const;
    self& operator+=(const difference_type n);
    self operator-(const difference_type n) const;
    self& operator-=(const difference_type n);
    reference operator[](const difference_type n) const;

    bool operator==(const self& rhv) const; 
    bool operator!=(const self& rhv) const; 
    bool operator<(const self& rhv)  const;
    bool operator>(const self& rhv)  const; 
    bool operator<=(const self& rhv) const; 
    bool operator>=(const self& rhv) const; 

private:
    iterator_type iterator_;
};

#include "../templates/Reverse_iterator.cpp"


template <typename RandomAccessIterator, typename T, typename Reference = T&, typename Distance = std::ptrdiff_t>
typename Reverse_iterator<RandomAccessIterator, T, Reference , Distance>::difference_type
operator-(const Reverse_iterator<RandomAccessIterator, T, Reference , Distance>& lhs, const Reverse_iterator<RandomAccessIterator, T, Reference , Distance>& rhs)
{
    return rhs.base() - lhs.base();
}

template <typename RandomAccessIterator, typename T, typename Reference = T&, typename Distance = std::ptrdiff_t>
Reverse_iterator<RandomAccessIterator, T, Reference , Distance>
operator+(typename Reverse_iterator<RandomAccessIterator, T, Reference , Distance>::difference_type n, const Reverse_iterator<RandomAccessIterator, T, Reference , Distance>& it)
{
    return it + n;
}


template <typename RandomAccessIterator, typename T, typename Reference = T&, typename Distance = std::ptrdiff_t>
typename std::iterator_traits<RandomAccessIterator>::iterator_category
iterator_category(const Reverse_iterator<RandomAccessIterator, T, Reference , Distance>&)
{
    return typename std::iterator_traits<RandomAccessIterator>::itaretor_category();
}

template <typename RandomAccessIterator, typename T, typename Reference = T&, typename Distance = std::ptrdiff_t>
T*
value_type(const Reverse_iterator<RandomAccessIterator, T, Reference , Distance>&)
{
    return (T*)0;
}

template <typename RandomAccessIterator, typename T, typename Reference = T&, typename Distance = std::ptrdiff_t>
Distance*
distance_type(const Reverse_iterator<RandomAccessIterator, T, Reference , Distance>&)
{
    return (Distance*)0;
}

#endif /// __REVERSE_ITERATOR_HPP__

