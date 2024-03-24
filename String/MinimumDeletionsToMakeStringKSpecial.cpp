#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for (auto &it : word) {
            freq[it - 'a']++;
        }

        int ans = 1e9;

        for (int l = 1; l <= 100000; l++) {
            int r = min(l + k, 100000);

            int cost = 0;

            for (int ch = 0; ch < 26; ch++) {
                if (freq[ch] < l)
                    cost += freq[ch];
                if (freq[ch] > r)
                    cost += freq[ch] - r;
            }

            ans = min(ans, cost);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string word = "abcabcabc";
    int k = 2;

    int result = sol.minimumDeletions(word, k);

    cout << "The minimum number of deletions to make the string special is: " << result << endl;

    return 0;
}