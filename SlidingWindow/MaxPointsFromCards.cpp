#include <iostream>
#include <vector>

using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int sm = 0;
    for (int i = 0; i < k; i++)
        sm += cardPoints[i];

    int currsm = sm;
    for (int i = k - 1; i >= 0; i--) {
        currsm -= cardPoints[i];
        currsm += cardPoints[n + i - k];
        sm = max(currsm, sm);
    }

    return sm;
}

int main() {
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    int result = maxScore(cardPoints, k);

    cout << "Maximum Score: " << result << endl;

    return 0;
}
