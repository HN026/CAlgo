#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    int timeRequiredToBuy(vector<int> &tickets, int k) {
        queue<int> q;
        int n = tickets.size();
        for (int i = 0; i < n; i++)
            q.push(i);

        int time = 0;
        while (!q.empty()) {
            time++;
            auto idx = q.front();
            q.pop();

            tickets[idx]--;
            if (k == idx && tickets[idx] == 0)
                break;
            if (tickets[idx] > 0)
                q.push(idx);
        }
        return time;
    }
};

int main() {
    vector<int> tickets = {2, 3, 2};
    int k = 2;
    Solution sol = Solution();
    cout << sol.timeRequiredToBuy(tickets, k) << endl;
    return 0;
}