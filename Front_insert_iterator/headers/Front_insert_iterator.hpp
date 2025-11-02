#ifndef __Front_insert_iterator_HPP__
#define __Front_insert_iterator_HPP__

#include <iterator>

template <typename FrontInsertSequence>
class Front_insert_iterator
{
public:
    typedef FrontInsertSequence      container_type;
    typedef std::output_iterator_tag iterator_category;
    typedef void                     value_type;
    typedef void                     difference_type;
    typedef void                     pointer;
    typedef void                     reference;

public:
    explicit Front_insert_iterator(FrontInsertSequence& x);
    Front_insert_iterator(const Front_insert_iterator<FrontInsertSequence>& rhv);

    Front_insert_iterator<FrontInsertSequence>& operator=(const Front_insert_iterator<FrontInsertSequence>& rhv);
    Front_insert_iterator<FrontInsertSequence>& operator*();	
    Front_insert_iterator<FrontInsertSequence>& operator=(const typename FrontInsertSequence::value_type& value);
    Front_insert_iterator<FrontInsertSequence>& operator++();
    Front_insert_iterator<FrontInsertSequence>& operator++(int);

private:
    FrontInsertSequence* container_;
};

template <class FrontInsertionSequence>
Front_insert_iterator<FrontInsertionSequence>
front_inserter(FrontInsertionSequence& S)
{
    return Front_insert_iterator<FrontInsertionSequence>(S);
}


template <typename FrontInsertSequence>
std::output_iterator_tag
iterator_category(const Front_insert_iterator<FrontInsertSequence>&)
{
    return std::output_iterator_tag();
}

#endif /// __Front_insert_iterator_HPP__

