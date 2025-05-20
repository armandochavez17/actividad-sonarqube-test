#include <gtest/gtest.h>
#include "../include/integradora.hpp"

TEST(KMP, Found) {
    EXPECT_EQ(kmpSearch("abcxabcdabcdabcy", "abcdabcy"), 9);
}

TEST(KMP, NotFound) {
    EXPECT_EQ(kmpSearch("abcabcabc", "xyz"), -1);
}

TEST(LPS, CorrectValues) {
    std::vector<int> expected = {0, 0, 1, 2, 0, 1, 2};
    EXPECT_EQ(computeLPS("ababcab"), expected);
}

TEST(Palindrome, Centered) {
    auto res = longestPalindrome("abcba");
    EXPECT_EQ(res, std::make_pair(1, 5));
}

TEST(LCS, Found) {
    auto res = findLongestCommonSubstring("abcdef", "zabcf");
    EXPECT_EQ(res, std::make_pair(1, 3));
}

TEST(File, EmptyFileReturnsZero) {
    EXPECT_EQ(longestPalindrome(""), std::make_pair(0, 0));
}
