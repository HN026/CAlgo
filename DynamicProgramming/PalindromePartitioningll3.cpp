#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(string &s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--]) {
            return false;
        }
    }
    return true;
}

int totalPartitions(string s) {
    int n = s.size();
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++) {
        dp[i] = i; // Represents the minimum number of cuts for every substring to be palindrome fro 0..i index
        for (int j = 0; j <= i; j++) {
            if (isPalindrome(s, j, i)) {
                dp[i] = (j == 0) ? 0 : min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    return dp[n - 1];
}

int main() {
    string s = "aaabc";
    int ans = totalPartitions(s);
    cout << ans << endl;
    return 0;
}