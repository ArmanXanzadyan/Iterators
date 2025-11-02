#ifndef __Raw_storage_iterator_HPP__
#define __Raw_storage_iterator_HPP__

#include <cstddef>
#include <new> 
#include <iterator> 

template <typename ForwardIterator, typename T>
class Raw_storage_iterator
{
public:
    typedef std::output_iterator_tag iterator_category;
    typedef void                     value_type;
    typedef std::ptrdiff_t           difference_type;
    typedef void                     pointer;
    typedef void                     reference;

    explicit Raw_storage_iterator(ForwardIterator iterator);
    Raw_storage_iterator(const Raw_storage_iterator<ForwardIterator, T>& rhv);

    Raw_storage_iterator& operator=(const Raw_storage_iterator<ForwardIterator, T>& rhv);
    Raw_storage_iterator& operator=(const T& value);
    Raw_storage_iterator& operator*();
    Raw_storage_iterator& operator++();
    Raw_storage_iterator  operator++(int); 
    ForwardIterator base() const;

private:
    ForwardIterator iterator_;
};

#include "../templates/Raw_storage_iterator.cpp"

template <typename ForwardIterator, typename T>
inline std::output_iterator_tag
iterator_category(const Raw_storage_iterator<ForwardIterator, T>&)
{
    return std::output_iterator_tag();
}

#endif /// __Raw_storage_iterator_HPP__

