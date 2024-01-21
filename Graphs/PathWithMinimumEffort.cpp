#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    priority_queue<
    pair<int, pair<int,int>>,
    vector<pair<int, pair<int,int>>>, 
    greater<pair<int, pair<int,int>>>
    >q;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    vector<vector<int>> effort(n, vector<int> (m, 1e9));
    effort[0][0] = 0;
    q.push({0, {0, 0}});

    while(!q.empty()){
        auto it = q.top();
        q.pop();
        int diff = it.first;
        int r = it.second.first;
        int c = it.second.second;

        if(r == n-1 && c == m-1) return diff;

        for(int i = 0; i<4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                int newEffort = max(abs(heights[nrow][ncol] - heights[r][c]), diff);
                if(newEffort < effort[nrow][ncol]){
                    effort[nrow][ncol] = newEffort;
                    q.push({newEffort, {nrow, ncol}});
                }
            }
        }
    }
    return 0;
}

int main() {
    // Example usage of the minimumEffortPath function
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    int result = minimumEffortPath(heights);

    cout << "Minimum effort to reach the bottom-right: " << result << endl;

    return 0;
}
