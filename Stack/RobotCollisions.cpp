#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions) {
        vector<int> ids;
        int n = positions.size();
        for (int i = 0; i < n; i++)
            ids.push_back(i);
        auto compare = [&](int id1, int id2) {
            return positions[id1] < positions[id2];
        };
        sort(ids.begin(), ids.end(), compare);

        stack<int> st;
        for (auto &id : ids) {
            if (directions[id] == 'R')
                st.push(id);
            else {
                while (!st.empty() && healths[id] > 0) {
                    if (healths[id] > healths[st.top()]) {
                        healths[id]--;
                        healths[st.top()] = 0;
                        st.pop();
                    } else if (healths[id] < healths[st.top()]) {
                        healths[id] = 0;
                        healths[st.top()]--;
                    } else {
                        healths[id] = 0;
                        healths[st.top()] = 0;
                        st.pop();
                    }
                }
            }
        }
        vector<int> ans;
        for (auto it : healths)
            if (it)
                ans.push_back(it);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> positions = {10, 5, 0};
    vector<int> healths = {1, 5, 3};
    string directions = "RLL";
    vector<int> survived = solution.survivedRobotsHealths(positions, healths, directions);
    cout << "Survived robots' healths: ";
    for (auto health : survived) {
        cout << health << " ";
    }
    cout << endl;
    return 0;
}