#ifndef __Back_inserter_iterator_HPP__
#define __Back_inserter_iterator_HPP__

#include <iterator>

template <typename BackInsertionSequence>
class Back_inserter_iterator
{
public:
    typedef BackInsertionSequence    container_type;
    typedef std::output_iterator_tag iterator_category;
    typedef void                     value_type;
    typedef void                     difference_type;
    typedef void                     pointer;
    typedef void                     reference;

public:
    explicit Back_inserter_iterator(BackInsertionSequence& x);
    Back_inserter_iterator(const Back_inserter_iterator<BackInsertionSequence>& rhv);

    Back_inserter_iterator<BackInsertionSequence>& operator=(const Back_inserter_iterator<BackInsertionSequence>& rhv);
    Back_inserter_iterator<BackInsertionSequence>& operator*();	
    Back_inserter_iterator<BackInsertionSequence>& operator=(const typename BackInsertionSequence::value_type& value);
    Back_inserter_iterator<BackInsertionSequence>& operator++();
    Back_inserter_iterator<BackInsertionSequence>& operator++(int);

private:
    BackInsertionSequence* container_;
};

template <class BackInsertionSequence>
Back_inserter_iterator<BackInsertionSequence>
back_inserter(BackInsertionSequence& S)
{
    return Back_inserter_iterator<BackInsertionSequence>(S);
}


template <typename BackInsertionSequence>
std::output_iterator_tag
iterator_category(const Back_inserter_iterator<BackInsertionSequence>&)
{
    return std::output_iterator_tag();
}

#endif /// __Back_inserter_iterator_HPP__

