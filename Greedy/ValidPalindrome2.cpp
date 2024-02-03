#include <iostream>

bool isPali(std::string s, int start, int end) {
    while (start <= end) {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

bool validPalindrome(std::string s) {
    int n = s.length();
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        if (s[left] != s[right]) {
            return isPali(s, left, right - 1) || isPali(s, left + 1, right);
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    // Test cases
    std::string test1 = "aba";
    std::string test2 = "racecar";
    std::string test3 = "abcd";

    bool result1 = validPalindrome(test1) ? true : false;
    bool result2 = validPalindrome(test2) ? true : false;
    bool result3 = validPalindrome(test3) ? true : false;

    std::cout << "Is 'aba' a valid palindrome? " << (result1 ? "Yes" : "No") << std::endl;
    std::cout << "Is 'racecar' a valid palindrome? " << (result2 ? "Yes" : "No") << std::endl;
    std::cout << "Is 'abcd' a valid palindrome? " << (result3 ? "Yes" : "No") << std::endl;

    return 0;
}
