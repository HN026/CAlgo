#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

class Solution {
    vector<int> parent;
    vector<vector<int>> adj;
    vector<ll> val;
    ll K;
public:

    void calculateParent(int root, int p){
        parent[root] = p;

        for(auto node: adj[root]){
            if(node!=p) calculateParent(node, root);
        }
    }

    long long dfs(int source, bool taken, 
    vector<vector<ll>> &dp){
        ll &ans = dp[source][taken];
        if(ans!=-1) return ans;

        ans = 0;
        ll min_diff = 1e9;
        ll best = 0;
        ll taken_in_best = 0;

        min_diff = min(min_diff, abs(val[source]-(val[source]^K)));
        best = max(val[source], val[source]^K);
        if(val[source]<(val[source]^K)) taken_in_best++;

        for(auto adjNode: adj[source]){
            if(adjNode == parent[source]) continue;

            ll with = dfs(adjNode, true,dp);
            ll without = dfs(adjNode, false, dp);

            min_diff = min(min_diff, abs(with-without));
            best += max(with, without);
            if(with>without) taken_in_best++;
        }

        taken_in_best = taken_in_best%2;
        if(taken_in_best == taken) return ans = best;
        return ans = best - min_diff;
    }


    long long maximumValueSum(vector<int>& nums, int k, 
    vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<ll>> dp(n, vector<ll> (2, -1));

        parent.resize(n);
        for(int i = 0; i<n; i++){
           parent[i] = i;
           val.push_back(nums[i]);
        }
        adj.resize(n);

        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        K = k;
        calculateParent(0, -1);
        return dfs(0, false, dp);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 1};
    int k = 3;
    vector<vector<int>> edges = {{0, 1}, {0, 2}};
    ll result = solution.maximumValueSum(nums, k, edges);
    cout << "The maximum value sum is: " << result << endl;
    return 0;
}