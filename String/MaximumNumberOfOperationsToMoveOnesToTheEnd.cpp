#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    int maxOperations(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();

        int startIndex = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                startIndex = i;
                break;
            }
        }

        if (startIndex == -1)
            return 0;
        int maxOps = 0;
        int impact = 1;
        int j = -1;
        for (int i = startIndex; i < n; i++) {
            if (s[i] == '0')
                continue;
            int cnt = 0;
            for (j = i; j < n; j++) {
                if (s[j] == '0')
                    break;
                cnt++;
            }
            maxOps += impact * cnt;
            impact++;
            i = j - 1;
        }

        return maxOps;
    }
};

int main() {
    Solution solution;
    string s = "110100110";
    cout << "Maximum number of operations: " << solution.maxOperations(s) << endl;
    return 0;
}