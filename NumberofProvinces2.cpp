#include <iostream>
#include <vector>
#include <queue>

// Using BFS

using namespace std;

int findCircleNum(vector<vector<int>> isConnected, int V){
    vector<int> vis(V, 0);
    int cnt = 0;
    for(int i = 0; i<V; i++){
        if(!vis[i]){
            cnt++;
            queue<int> q;
            q.push(i);
            if(!q.empty()){
                int node = q.front();
                q.pop();
                vis[node] = 1;
                for(int j = 0; j<V; j++){
                    if(isConnected[node][j]==1 && !vis[j] && node!=j){
                        q.push(j);
                    }
                }            
            }
        }
    }
    return cnt;
}




int main(){

    vector<vector<int>> isConnected = {{1,1,0}, {1,1,0}, {0,0,1}};

    int a = findCircleNum(isConnected, 3);
    cout<<a<<" "<<endl;
    return 0;
}