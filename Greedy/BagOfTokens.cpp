#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int bagOfTokensScore(vector<int> &tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        if (n == 0)
            return 0;

        int i = 0;
        int j = n - 1;
        int score = 0;
        int maxScore = INT_MIN;
        while (i <= j) {
            if (tokens[i] <= power) {
                score++;
                power = power - tokens[i];
                i++;
            } else if (tokens[i] > power && score != 0) {
                score--;
                power = power + tokens[j];
                j--;
            } else {
                return 0;
            }
            maxScore = max(maxScore, score);
        }

        return maxScore;
    }
};

int main() {
    Solution solution;
    vector<int> tokens = {100, 200, 300, 400};
    int power = 200;
    int result = solution.bagOfTokensScore(tokens, power);
    cout << "The maximum score that can be achieved with " << power << " power is: " << result << endl;
    return 0;
}