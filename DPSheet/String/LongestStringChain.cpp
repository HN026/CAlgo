#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static bool comp(const string &a, const string &b) {
    return a.size() < b.size();
}

bool isPossible(string &a, string &b) {
    int n = a.size();
    int m = b.size();

    if (n + 1 != m)
        return false;
    int first = 0;
    int second = 0;

    while (second < m) {
        if (a[first] == b[second]) {
            first++;
            second++;
        } else {
            second++;
        }
    }

    if (first == n && second == m)
        return true;
    return false;
}

class Solution {
  public:
    int longestStrChain(vector<string> &words) {
        int n = words.size();
        vector<int> dp(n, 1);

        int maxi = 1;
        sort(words.begin(), words.end(), comp);

        for (int index = 0; index < n; index++) {
            for (int prev = 0; prev < index; prev++) {
                if (isPossible(words[prev], words[index]) &&
                    dp[index] < dp[prev] + 1) {
                    dp[index] = dp[prev] + 1;
                }
            }
            maxi = max(maxi, dp[index]);
        }

        return maxi;
    }
};

int main() {
    // Create a vector of words
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};

    // Calculate the longest string chain
    int result = Solution().longestStrChain(words);

    // Print the result
    cout << "The longest string chain is: " << result << endl;

    return 0;
}