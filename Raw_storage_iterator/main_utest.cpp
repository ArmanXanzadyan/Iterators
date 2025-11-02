#include <gtest/gtest.h>
#include "headers/Raw_storage_iterator.hpp"
#include <cstdlib> 
#include <algorithm> 
#include <functional> 
#include <iostream>

class Int {
public:
    explicit Int(int x = 0) : value_(x) { ++constructed_; }
    ~Int() { ++destroyed_; }
    int get() const { return value_; }

    static void resetCounters() {
        constructed_ = 0;
        destroyed_ = 0;
    }

    static int constructed_;
    static int destroyed_;

private:
    int value_;
};

int Int::constructed_ = 0;
int Int::destroyed_ = 0;

TEST(RawStorageIteratorTest, ConstructsObjectsInRawMemory)
{
    Int::resetCounters();

    int src[] = {1, 2, 3, 4};
    const std::size_t N = sizeof(src) / sizeof(src[0]);

    // Allocate raw memory for N Int objects
    void* raw = std::malloc(N * sizeof(Int));
    ASSERT_TRUE(raw != 0);

    Int* dst = static_cast<Int*>(raw);

    std::transform(src, src + N,
                   Raw_storage_iterator<Int*, int>(dst),
                   std::negate<int>());

    for (std::size_t i = 0; i < N; ++i) {
        EXPECT_EQ(dst[i].get(), -src[i]);
    }

    EXPECT_EQ(Int::constructed_, static_cast<int>(N));

    for (std::size_t i = 0; i < N; ++i)
        dst[i].~Int();

    std::free(raw);

    EXPECT_EQ(Int::destroyed_, static_cast<int>(N));
}

TEST(RawStorageIteratorTest, CopyAndAssignment)
{
    int data[3] = {0};
    Raw_storage_iterator<int*, int> it1(data);
    Raw_storage_iterator<int*, int> it2(it1);
    Raw_storage_iterator<int*, int> it3 = it1;

    // Copy & assignment must point to same base
    EXPECT_EQ(it1.base(), data);
    EXPECT_EQ(it2.base(), data);
    EXPECT_EQ(it3.base(), data);

    // Increment operator
    ++it1;
    EXPECT_EQ(it1.base(), data + 1);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

