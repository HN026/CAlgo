#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void floodFill(vector<vector<int>> &image, int sr, int sc, int color){
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> vis(n, vector<int> (m,0));
    queue<pair<int,int>> q;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0,1,0,-1};
    q.push({sr,sc});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i = 0; i<4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && vis[nrow][ncol]==0 && image[nrow][ncol]==1){
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
                image[nrow][ncol] = color;
            }
        }
    }
    
}

int main(){
    vector<vector<int>> image = {{1,1,1}, {1,1,0}, {1,0,1}};
    floodFill(image, 1, 1, 2);
    for(int i = 0; i<image.size(); i++){
        for(int j = 0; j<image[0].size(); j++){
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}