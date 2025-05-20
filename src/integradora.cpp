#include "../include/integradora.hpp"
#include <fstream>
#include <iostream>

std::string readFileContent(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) return "";

    std::string content, line;
    while (std::getline(file, line)) {
        content += line + "\n";
    }
    file.close();

    if (!content.empty() && content.back() == '\n') {
        content.pop_back();
    }

    return content;
}

std::vector<int> computeLPS(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> lps(m, 0);
    int len = 0, i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else {
            len = (len != 0) ? lps[len - 1] : 0;
            if (len == 0) lps[i++] = 0;
        }
    }
    return lps;
}

int kmpSearch(const std::string& text, const std::string& pattern) {
    int n = text.length(), m = pattern.length();
    if (m == 0) return -1;

    std::vector<int> lps = computeLPS(pattern);
    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++, j++;
            if (j == m) return (i - j) + 1;
        } else {
            j = (j != 0) ? lps[j - 1] : 0;
            if (j == 0) i++;
        }
    }
    return -1;
}

std::pair<int, int> longestPalindrome(const std::string& s) {
    if (s.empty()) return {0, 0};

    int n = s.length(), maxLength = 1, start = 0;
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));

    for (int i = 0; i < n; i++) dp[i][i] = true;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for (int k = 3; k <= n; k++) {
        for (int i = 0; i < n - k + 1; i++) {
            int j = i + k - 1;
            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp[i][j] = true;
                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    return {start + 1, start + maxLength};
}

std::pair<int, int> findLongestPalindromeInFile(const std::string& fileName) {
    std::string fullText = readFileContent(fileName);
    return longestPalindrome(fullText);
}

std::pair<int, int> findLongestCommonSubstring(const std::string& text1, const std::string& text2) {
    int m = text1.length(), n = text2.length(), maxLength = 0, endIndex = 0;
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }

    if (maxLength == 0) return {0, 0};
    int startIndex = endIndex - maxLength + 1;
    return {startIndex + 1, endIndex + 1};
}
