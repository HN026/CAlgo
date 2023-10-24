#include <iostream>
#include <vector>

// Using DFS

using namespace std;

void dfs(int start, vector<int> adjList[], int vis[]){
    vis[start] = 1;
    for(auto it: adjList[start]){
        if(!vis[it]){
            dfs(it, adjList, vis);
        }
    }
}


int findCircleNum(vector<vector<int>> isConnected, int V){
    vector<int> adjList[V];
    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            if(isConnected[i][j]==1 && i!=j){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    int cnt = 0;
    int vis[3] = {0};
    for(int i = 0; i<V; i++){
        if(!vis[i]){
            cnt++;
            dfs(i, adjList, vis);
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