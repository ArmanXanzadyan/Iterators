#ifndef __Insert_iterator_HPP__
#define __Insert_iterator_HPP__

#include <iterator>

template <typename Container>
class Insert_iterator
{
public:
    typedef Container                      container_type;
    typedef std::output_iterator_tag       iterator_category;
    typedef typename Container::value_type value_type;
    typedef void                           difference_type;
    typedef void                           pointer;
    typedef void                           reference;

public:
    explicit Insert_iterator(Container& x, typename Container::iterator it);
    Insert_iterator(const Insert_iterator<Container>& rhv);

    Insert_iterator<Container>& operator=(const Insert_iterator<Container>& rhv);
    Insert_iterator<Container>& operator*();	
    Insert_iterator<Container>& operator=(const typename Container::value_type& value);
    Insert_iterator<Container>& operator++();
    Insert_iterator<Container>& operator++(int);

private:
    Container& container_;
    typename Container::iterator iterator_;

};

template <typename Container>
Insert_iterator<Container>
inserter(Container& C, typename Container::iterator it)
{
    return Insert_iterator<Container>(C, it);
}


template <typename Container>
std::output_iterator_tag
iterator_category(const Insert_iterator<Container>&)
{
    return std::output_iterator_tag();
}

#endif /// __Insert_iterator_HPP__

