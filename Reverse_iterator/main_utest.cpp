#include <gtest/gtest.h>
#include "headers/Reverse_iterator.hpp"
#include <vector>

typedef std::vector<int>::iterator VecIter;
typedef Reverse_iterator<VecIter, int> RevIter;

class ReverseIteratorTest : public ::testing::Test
{
protected:
    std::vector<int> v_;
    void SetUp()
    {
        v_.push_back(10);
        v_.push_back(20);
        v_.push_back(30);
        v_.push_back(40);
        v_.push_back(50);
    }
};

TEST_F(ReverseIteratorTest, DereferenceOperator)
{
    RevIter rit(v_.end());
    EXPECT_EQ(*rit, 50);
    ++rit;
    EXPECT_EQ(*rit, 40);
}

TEST_F(ReverseIteratorTest, ArrowOperator)
{
    struct S { int val; };
    S arr[2]; arr[0].val = 1; arr[1].val = 2;
    Reverse_iterator<S*, S> rit(arr + 2);
    EXPECT_EQ(rit->val, 2);
}

TEST_F(ReverseIteratorTest, IncrementDecrement)
{
    RevIter rit(v_.end());
    EXPECT_EQ(*rit, 50);

    ++rit;
    EXPECT_EQ(*rit, 40);

    rit++;
    EXPECT_EQ(*rit, 30);

    --rit;
    EXPECT_EQ(*rit, 40);

    rit--;
    EXPECT_EQ(*rit, 50);
}

TEST_F(ReverseIteratorTest, ArithmeticOperators)
{
    RevIter rit(v_.end());
    RevIter rit2 = rit + 2;
    EXPECT_EQ(*rit2, 30);

    rit2 = rit2 - 1;
    EXPECT_EQ(*rit2, 40);

    rit2 += 2;
    EXPECT_EQ(*rit2, 20);

    rit2 -= 1;
    EXPECT_EQ(*rit2, 30);
}

TEST_F(ReverseIteratorTest, SubscriptOperator)
{
    RevIter rit(v_.end());
    EXPECT_EQ(rit[0], 50);
    EXPECT_EQ(rit[1], 40);
    EXPECT_EQ(rit[2], 30);
}

TEST_F(ReverseIteratorTest, ComparisonOperators)
{
    RevIter rit1(v_.end());
    RevIter rit2(v_.end() - 2);

    EXPECT_TRUE(rit1 != rit2);
    EXPECT_TRUE(rit2 < rit1);
    EXPECT_TRUE(rit1 > rit2);
    EXPECT_TRUE(rit1 >= rit2);
    EXPECT_TRUE(rit2 <= rit1);

    RevIter rit3 = rit1;
    EXPECT_TRUE(rit3 == rit1);
}

TEST_F(ReverseIteratorTest, BaseFunction)
{
    RevIter rit(v_.end());
    EXPECT_EQ(rit.base(), v_.end());
    ++rit;
    EXPECT_EQ(rit.base(), v_.end() - 1);
}

TEST_F(ReverseIteratorTest, GlobalOperators)
{
    RevIter rit1(v_.end());
    RevIter rit2(v_.end() - 3);

    EXPECT_EQ(rit2 - rit1, 3);
    RevIter rit3 = 2 + rit1;
    EXPECT_EQ(*rit3, 30);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

