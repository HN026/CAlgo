#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> getOrder(vector<vector<int>> &tasks){
    int n = tasks.size();
    for(int i = 0; i<n; i++) tasks[i].push_back(i);
    vector<int> ans;
    sort(tasks.begin(), tasks.end());

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    int i = 0;
    long long curTime = tasks[0][0];
    pq.push({tasks[0][1], tasks[0][2]});
    while(ans.size()<n){
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            curTime += it.first;
            ans.push_back(it.second);

            for(int j = i+1; j<n && curTime>=tasks[j][0]; j++){
                pq.push({tasks[j][1], tasks[j][2]});
                i = j;
            }
        }
        if(i+1<n && pq.empty()){
            curTime = tasks[i+1][0];
            pq.push({tasks[i+1][1], tasks[i+1][2]});
            i++;
        }
    }

    return ans;
}

int main(){
    vector<vector<int>> tasks = {
        {1,2},
        {2,4},
        {3,2},
        {4,1}
    };
    vector<int> ans = getOrder(tasks);
    for(auto &it: ans){
        cout<<it<<" ";
    }

    return 0;
}