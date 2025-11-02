#include <gtest/gtest.h>
#include <sstream>
#include "headers/Istream_iterator.hpp"
#include <vector>
#include <algorithm>

TEST(IstreamIteratorTest, CopyAndIncrement)
{
    std::istringstream ss("10 20 30");
    Istream_iterator<int> it(ss);
    Istream_iterator<int> end;

    EXPECT_EQ(*it, 10);
    ++it;
    EXPECT_EQ(*it, 20);

    Istream_iterator<int> copy_it = it; // copy constructor
    EXPECT_EQ(*copy_it, 20);

    Istream_iterator<int> post_it = it++;
    EXPECT_EQ(*post_it, 20); // previous value
    EXPECT_EQ(*it, 30);      // incremented value

    // Copy to vector
    std::vector<int> v;
    std::copy(Istream_iterator<int>(ss), end, std::back_inserter(v));
    EXPECT_TRUE(v.empty()); // ss is already at EOF
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

