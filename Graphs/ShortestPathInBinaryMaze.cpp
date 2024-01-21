#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> &source, pair<int, int> &destination){
    if(source.first==destination.first && source.second == destination.second) return 0;

    int n = grid.size();
    int m = grid[0].size();
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    vector<vector<int>> dist(n, vector<int> (m, 1e9));
    dist[source.first][source.second] = 0;
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {source.first, source.second}});

    while(!q.empty()){
        auto it = q.front();
        int distance = it.first;
        int r = it.second.first;
        int c = it.second.second;
        q.pop();

        for(int i = 0; i<4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && 1+distance<dist[nrow][ncol]){
                dist[nrow][ncol] = 1 + distance;
                if(nrow==destination.first && ncol==destination.second) return dist[nrow][ncol];
                q.push({dist[nrow][ncol], {nrow, ncol}});
            }
        }
    }

    return -1;
}

int main(){
    pair<int, int> source, destination;
    source.first = 0;
    source.second = 1;

    destination.first = 2;
    destination.second = 2;

    vector<vector<int>> grid = 
    {{1, 1, 1, 1},
    {1, 1, 0, 1},
    {1, 1, 1, 1},
    {1, 1, 0, 0},
    {1, 0, 0, 1}};

    int res = shortestPath(grid, source, destination);
    cout<<res<<endl;

    return 0;
}