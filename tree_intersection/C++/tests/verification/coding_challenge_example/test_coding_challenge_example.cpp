#include "gtest/gtest.h"
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

TEST(TestCodingChallengeExample, test2) {

    std::system("../source/tree_intersection_run ../../tests/verification/coding_challenge_example/input.json");

    std::array<char, 128> buffer;
    std::string differences;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen("diff ./output.json ../../tests/verification/coding_challenge_example/gold/output.json", "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        differences += buffer.data();
    }


    EXPECT_TRUE(differences.empty());
    std::system("rm ./output.json");
}