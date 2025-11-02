#ifndef __ITERATOR_TRAITS_AND_FUNCTON_HPP__
#define __ITERATOR_TRAITS_AND_FUNCTON_HPP__

#include <iostream>
#include <cstddef>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <limits>

namespace Iterator
{
        ///================TAGS================

class output_iterator_tag        {};
class input_iterator_tag         {};
class forward_iterator_tag       {};
class bidirectional_iterator_tag {};
class random_access_iterator_tag {};

///    ===================ITERATORS================

struct output_iterator
{
    typedef output_iterator_tag iterator_category;
};    

template <typename T, typename Distance>
struct input_iterator
{
    typedef input_iterator_tag iterator_category;
    typedef T                  value_type;
    typedef T*                 pointer;
    typedef value_type&        reference;
    typedef Distance           difference_type;
};

template <typename T, typename Distance>
struct forward_iterator
{
    typedef forward_iterator_tag iterator_category;
    typedef T                    value_type;
    typedef T*                   pointer;
    typedef value_type&          reference;
    typedef Distance             difference_type;
};

template <typename T, typename Distance>
struct bidirectional_iterator
{
    typedef bidirectional_iterator_tag iterator_category;
    typedef T                          value_type;
    typedef T*                         pointer;
    typedef value_type&                reference;
    typedef Distance                   difference_type;
};

template <typename T, typename Distance>
struct random_access_iterator
{
    typedef random_access_iterator_tag iterator_category;
    typedef T                          value_type;
    typedef T*                         pointer;
    typedef value_type&                reference;
    typedef Distance                   difference_type;
};

///=============================VALUE_TYPE===================================

template <typename T, typename Distance>
inline T*
value_type(const input_iterator<T, Distance>&)
{
    return reinterpret_cast<T*>(NULL);
}

template <typename T, typename Distance>
inline T*
value_type(const forward_iterator<T, Distance>&)
{
    return reinterpret_cast<T*>(NULL);
}

template <typename T, typename Distance>
inline T*
value_type(const bidirectional_iterator<T, Distance>&)
{
    return reinterpret_cast<T*>(NULL);
}

template <typename T, typename Distance>
inline T*
value_type(const random_access_iterator<T, Distance>&)
{
    return reinterpret_cast<T*>(NULL);
}

template <typename T, typename Distance>
inline T*
value_type(const T*)
{
    return reinterpret_cast<T*>(NULL);
}

///===========================DISTANCE_TYPE==================

template <typename T, typename Distance> 
inline Distance* 
distance_type(const input_iterator<T, Distance>&)
{
    return static_cast<Distance*>(NULL);
}

template <typename T, typename Distance> 
inline Distance*
distance_type(const forward_iterator<T, Distance>&)
{
    return static_cast<Distance*>(NULL);
}

template <typename T, typename Distance> 
inline Distance* 
distance_type(const bidirectional_iterator<T, Distance>&)
{
    return static_cast<Distance*>(NULL);
}

template <typename T, typename Distance> 
inline Distance*
distance_type(const random_access_iterator<T, Distance>&)
{
    return static_cast<Distance*>(NULL);
}

template <typename T>
inline std::ptrdiff_t*
distance_type(const T*)
{
    return static_cast<std::ptrdiff_t*>(NULL);
}

///=============================ITERATOR_CATEGORY=================

inline output_iterator_tag
iterator_category(const output_iterator&)
{
    return output_iterator_tag();
}

template <typename T, typename Distance>
inline input_iterator_tag
iterator_category(const input_iterator<T, Distance>&)
{
    return input_iterator_tag();
}

template <typename T, typename Distance>
inline forward_iterator_tag
iterator_category(const forward_iterator<T, Distance>&)
{
    return forward_iterator_tag();
}

template <typename T, typename Distance>
inline bidirectional_iterator_tag
iterator_category(const bidirectional_iterator<T, Distance>&)
{
    return bidirectional_iterator_tag();
}

template <typename T, typename Distance>
inline random_access_iterator_tag
iterator_category(const random_access_iterator<T, Distance>&)
{
    return random_access_iterator_tag();
}

///===========================ITERATOR_TRAITS=================

template <typename Iterator>
struct iterator_traits
{
    typedef typename Iterator::iterator_category iterator_category;
    typedef typename Iterator::value_type        value_type;
    typedef typename Iterator::difference_type   difference_type;
    typedef typename Iterator::pointer           pointer;
    typedef typename Iterator::reference         reference;
};

template <typename T>
struct iterator_traits<T*>
{
    typedef random_access_iterator_tag iterator_category;
    typedef T                          value_type;
    typedef ptrdiff_t                  difference_type;
    typedef T*                         pointer;
    typedef T&                         reference;
};

///============================ITERATOR========================

template <typename Category, typename T,
          typename Distance = std::ptrdiff_t,
          typename Pointer = T*,
          typename Reference = T&>
struct iterator
{
    typedef Category  iterator_category;
    typedef T         value_type;
    typedef Distance  difference_type;
    typedef Pointer   pointer;
    typedef Reference reference;
};

///===========================ITER_SWAP===================================

template <typename ForwardIterator>
inline void
iter_swap(ForwardIterator a, ForwardIterator b)
{
    return iter_swap_helper(a, b, typename Iterator::iterator_traits<ForwardIterator>::pointer());
}

template <typename ForwardIterator, typename ValueType>
inline void
iter_swap_helper(ForwardIterator a, ForwardIterator b, ValueType*)
{
    ValueType temp = *a;
    *a = *b;
    *b = temp;
}

///==========================REVERSE==========================================

template <typename BidirectionIterator>
inline void
reverse_helper(BidirectionIterator first, BidirectionIterator last, bidirectional_iterator_tag)
{
    while (true) {
        if (first == last || first == --last) return;
        iter_swap(first++, last);
    }
}

template <typename RandomAccessIterator>
inline void
reverse_helper(RandomAccessIterator first, RandomAccessIterator last, random_access_iterator_tag)
{
    while (first < last) {
        iter_swap(first++, --last);    
    }
}

template <typename BidirectionIterator>
inline void
reverse(BidirectionIterator first, BidirectionIterator last)
{
    reverse_helper(first, last, Iterator::iterator_traits<BidirectionIterator>::iterator_category());
}

///===============================MAX==============================================

template <typename ForwardIterator>
typename iterator_traits<ForwardIterator>::value_type
max(ForwardIterator first, ForwardIterator last)
{
    typename iterator_traits<ForwardIterator>::value_type max = std::numeric_limits<typename iterator_traits<ForwardIterator>::value_type>::min();
    for (; first != last; ++first) {
        if (*first > max) {
            max = *first;
        }
    }
    return max;
}

///================================DISTANCE===============================================

template <typename EveryIterator>
inline typename iterator_traits<EveryIterator>::difference_type
distance_helper(EveryIterator first, EveryIterator last, random_access_iterator_tag)
{
    return last - first;
}

template <typename pointer_traits>
inline typename iterator_traits<pointer_traits>::difference_type
distance_helper(pointer_traits first, pointer_traits last, ...)
{
    typename iterator_traits<pointer_traits>::difference_type distance = 0;
    while (first++ != last) {
        ++distance;
    }
    return distance;
}

template <typename InputIterator>
inline typename iterator_traits<InputIterator>::difference_type
distance(InputIterator first, InputIterator last)
{
    return distance_helper(first, last, typename Iterator::iterator_traits<InputIterator>::iterator_category());
}

///========================================ADVANCE===============================================================

template <typename InputIterator, typename Distance>
void 
advance_helper(InputIterator& it, Distance count, random_access_iterator_tag)
{
    it += count;
}

template <typename InputIterator, typename Distance>
void 
advance_helper(InputIterator& it, Distance count, ...)
{
    for (Distance i = 0; i < count; ++i) {
        ++it;
    }
}

template <typename InputIterator, typename Distance>
void 
advance(InputIterator& it, Distance count)
{
    advance_helper(it, count, typename Iterator::iterator_traits<InputIterator>::iterator_category());
}


} /// end namespace 

#endif /// __ITERATOR_TRAITS_AND_FUNCTON_HPP__

