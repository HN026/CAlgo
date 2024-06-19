#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        int finalCapital = w;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        priority_queue<int> maxHeap;

        for (int i = 0; i < n; i++) minHeap.push({capital[i], profits[i]});

        while (k > 0) {
            while (!minHeap.empty() && minHeap.top().first <= finalCapital) {
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }

            if (maxHeap.empty()) break;

            finalCapital += maxHeap.top();
            maxHeap.pop();
            k--;
        }

        return finalCapital;
    }
};

int main() {
    Solution sol;
    vector<int> profits = {1, 2, 3}; // Example profits
    vector<int> capital = {0, 1, 2}; // Example capital required for each project
    int k = 2; // Number of projects that can be selected
    int w = 0; // Initial capital

    int result = sol.findMaximizedCapital(k, w, profits, capital);
    cout << "Maximized Capital: " << result << endl;  // Expected output is 4
    return 0;
}
