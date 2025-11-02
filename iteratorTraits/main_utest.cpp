#include "headers/iteratorTraitsAndFunction.hpp"
#include "headers/function.hpp"
#include "headers/Vector.hpp"
#include "headers/List.hpp"
#include <gtest/gtest.h>

TEST(a, b)
{
    typedef Vector<int> C;
    C a(2, 3);
    C b(10);
    iota(b.begin(), b.end(), 11);
    print(b.begin(), b.end());
    Iterator::reverse(b.begin(), b.end());
    print(b.begin(), b.end());
    
    EXPECT_TRUE(Iterator::max(b.begin(), b.end()) == *std::max_element(b.begin(), b.end()));
    EXPECT_TRUE(Iterator::distance(b.begin(), b.end()) == static_cast<Iterator::iterator_traits<Vector<int>::iterator>::value_type>(b.size()));
    
    Vector<int>::iterator it = b.begin();
    EXPECT_TRUE(it == b.begin());
    Iterator::advance(it, 5);
    EXPECT_TRUE(it == b.begin() + 5);
    
    Iterator::iter_swap(a.begin(), b.begin());
    EXPECT_TRUE(3 == *b.begin());
    EXPECT_TRUE(20 == *a.begin());
    
    std::random_shuffle(b.begin(), b.end());
}

TEST(a, c)
{
    typedef List<int> C;
    C a(2, 3);
    C b(10);
    iota(b.begin(), b.end(), 11);
    Iterator::iter_swap(a.begin(), b.begin());
    print(b.begin(), b.end());
    
    EXPECT_TRUE(Iterator::max(b.begin(), b.end()) == *std::max_element(b.begin(), b.end()));
    EXPECT_TRUE(Iterator::distance(b.begin(), b.end()) == static_cast<Iterator::iterator_traits<Vector<int>::iterator>::value_type>(b.size()));
    List<int>::iterator it = b.begin();
    EXPECT_TRUE(*it == 3);
    Iterator::advance(it, 5);
    EXPECT_TRUE(*it == 16);
    
    Iterator::reverse(b.begin(), b.end());
    print(b.begin(), b.end());
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

