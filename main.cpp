#include <iostream>
#include "include/integradora.hpp"

int main() {
    std::string files[2] = {"transmission1.txt", "transmission2.txt"};
    std::string patterns[3] = {"mcode1.txt", "mcode2.txt", "mcode3.txt"};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::string pattern = readFileContent(patterns[j]);
            std::string file = readFileContent(files[i]);
            if (pattern.empty()) continue;

            int index = kmpSearch(file, pattern);
            std::cout << (index != -1 ? "true " + std::to_string(index) : "false") << std::endl;
        }
    }

    for (const auto& file : files) {
        auto palindrome = findLongestPalindromeInFile(file);
        std::cout << palindrome.first << " " << palindrome.second << std::endl;
    }

    std::string content1 = readFileContent(files[0]);
    std::string content2 = readFileContent(files[1]);
    if (!content1.empty() && !content2.empty()) {
        auto lcs = findLongestCommonSubstring(content1, content2);
        std::cout << lcs.first << " " << lcs.second << std::endl;
    }

    return 0;
}
