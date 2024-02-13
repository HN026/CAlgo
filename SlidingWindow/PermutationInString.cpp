#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        int left = 0;
        int cnt = 0;
        vector<int> s(26, 0);
        for (int i = 0; i < n; i++) {
            s[s1[i] - 'a']++;
        }
        vector<int> temp(26, 0);
        for (int right = 0; right < m; right++) {
            cnt++;
            temp[s2[right] - 'a']++;

            while (cnt == n) {
                if (temp == s)
                    return true;
                temp[s2[left] - 'a']--;
                left++;
                cnt--;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    string s1 = "abc";
    string s2 = "eidbaooo";
    bool result = sol.checkInclusion(s1, s2);
    cout << (result ? "True" : "False") << endl;
    return 0;
}