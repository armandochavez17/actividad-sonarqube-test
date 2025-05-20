#ifndef INTEGRADORA_HPP
#define INTEGRADORA_HPP

#include <string>
#include <vector>

std::string readFileContent(const std::string& fileName);
std::vector<int> computeLPS(const std::string& pattern);
int kmpSearch(const std::string& text, const std::string& pattern);
std::pair<int, int> longestPalindrome(const std::string& s);
std::pair<int, int> findLongestPalindromeInFile(const std::string& fileName);
std::pair<int, int> findLongestCommonSubstring(const std::string& text1, const std::string& text2);

#endif
