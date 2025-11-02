#include <gtest/gtest.h>
#include "headers/Reverse_bidirectional_iterator.hpp"
#include <list>

typedef std::list<int>::iterator ListIter;
typedef Reverse_bidirectional_iterator<ListIter, int> RevBidIter;

class ReverseBidirectionalIteratorTest : public ::testing::Test
{
protected:
    std::list<int> lst_;
    void SetUp()
    {
        lst_.push_back(10);
        lst_.push_back(20);
        lst_.push_back(30);
        lst_.push_back(40);
        lst_.push_back(50);
    }
};

TEST_F(ReverseBidirectionalIteratorTest, DereferenceOperator)
{
    RevBidIter rit(lst_.end());
    EXPECT_EQ(*rit, 50);
    ++rit;
    EXPECT_EQ(*rit, 40);
}

TEST_F(ReverseBidirectionalIteratorTest, PreIncrementAndPostIncrement)
{
    RevBidIter rit(lst_.end());
    EXPECT_EQ(*rit, 50);

    ++rit;
    EXPECT_EQ(*rit, 40);

    rit++;
    EXPECT_EQ(*rit, 30);
}

TEST_F(ReverseBidirectionalIteratorTest, PreDecrementAndPostDecrement)
{
    RevBidIter rit(lst_.end());
    ++rit;
    ++rit;
    EXPECT_EQ(*rit, 30);

    --rit;
    EXPECT_EQ(*rit, 40);

    rit--;
    EXPECT_EQ(*rit, 50);
}

TEST_F(ReverseBidirectionalIteratorTest, EqualityAndInequality)
{
    RevBidIter rit1(lst_.end());
    RevBidIter rit2(lst_.end());
    RevBidIter rit3(lst_.begin());

    EXPECT_TRUE(rit1 == rit2);
    EXPECT_FALSE(rit1 != rit2);
    EXPECT_TRUE(rit1 != rit3);
}

TEST_F(ReverseBidirectionalIteratorTest, BaseFunction)
{
    ListIter end_it = lst_.end();
    RevBidIter rit(end_it);
    EXPECT_EQ(rit.base(), end_it);

    ++rit;
    ListIter expected = end_it;
    --expected;
    EXPECT_EQ(rit.base(), expected);
}

TEST_F(ReverseBidirectionalIteratorTest, CopyConstructorAndAssignment)
{
    RevBidIter rit1(lst_.end());
    ++rit1;
    EXPECT_EQ(*rit1, 40);

    RevBidIter rit2(rit1);
    EXPECT_EQ(*rit2, 40);

    RevBidIter rit3;
    rit3 = rit1;
    EXPECT_EQ(*rit3, 40);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

