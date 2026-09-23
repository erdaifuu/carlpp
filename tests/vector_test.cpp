#include <gtest/gtest.h>
#include <carstl/vector.h>

TEST(Vector, DefaultEmpty) {
    carstl::vector<int> v;
    EXPECT_EQ(v.size(), 0);
}