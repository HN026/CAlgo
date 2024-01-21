#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    if(n-1==0 && m-1==0 && grid[0][0]==0) return 1;
    if(n-1==0 && m-1==0 && grid[0][0]) return -1;
    if(grid[0][0]==1) return -1;

    vector<vector<int>> dist(n, vector<int> (m, 1e9));
    queue<pair<int, pair<int,int>>> q;
    dist[0][0] = 0;
    q.push({0, {0, 0}});

    while(!q.empty()){
        auto it = q.front();
        int distance = it.first;
        int r = it.second.first;
        int c = it.second.second;
        q.pop();

        for(int drow = -1; drow<=1; drow++){
            for(int dcol = -1; dcol<=1; dcol++){
                int nrow = r + drow;
                int ncol = c + dcol;

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && 1 + distance < dist[nrow][ncol]){
                    dist[nrow][ncol] = 1 + distance;
                    if(nrow==n-1 && ncol==m-1) return 1+dist[nrow][ncol];
                    q.push({dist[nrow][ncol], {nrow,ncol}});
                }
            }
        }
    }
    return -1;
}

int main() {
    // Example grid
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 1, 0}
    };

    // Call the function
    int result = shortestPathBinaryMatrix(grid);

    // Display the result
    if (result != -1) {
        cout << "Shortest path length: " << result << endl;
    } else {
        cout << "No valid path exists." << endl;
    }

    return 0;
}
