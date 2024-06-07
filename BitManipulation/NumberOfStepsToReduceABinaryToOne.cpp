#include <iostream>

using namespace std;

class Solution {
  public:
    int numSteps(string s) {
        int carry = 0;
        int steps = 0;
        int n = s.size();

        for (int i = n - 1; i > 0; i--) {
            if ((s[i] - '0' + carry) % 2 == 1) {
                carry = 1;
                steps += 2;
            } else {
                steps += 1;
            }
        }
        return carry + steps;
    }
};

int main() {
    string s = "1101";
    Solution sol = Solution();
    cout << sol.numSteps(s) << endl;
    return 0;
}