#include "gtest/gtest.h"
#include <stdlib.h>

TEST(TestRepeatValues, test6) {
    std::system("rm ./output.json");
    std::system("../../../build/source/tree_intersection input.json");
    EXPECT_TRUE(std::system("diff ./ouput.json ./gold/output.json"));
}