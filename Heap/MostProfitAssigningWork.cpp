#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    priority_queue<pair<int, int>> works;
    priority_queue<int> workers;
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        for(int i = 0; i<n; i++) works.push({profit[i], difficulty[i]});
        for(int i = 0; i<m; i++) workers.push(worker[i]);    
        int maxProfit = 0;

        while(!works.empty() && !workers.empty()){
            while(!works.empty() && works.top().second > workers.top()){
                works.pop();
            };
            if(works.empty()) break;
            maxProfit += works.top().first;
            workers.pop();
        }
        
        return maxProfit;
    }
};



int main(){
    Solution s = Solution();
    vector<int> difficulty = {85,47,57};
    vector<int> profit = {24,66,99};
    vector<int> worker = {40,25,25};
    cout << s.maxProfitAssignment(difficulty, profit, worker) << endl;
    return 0;
}
