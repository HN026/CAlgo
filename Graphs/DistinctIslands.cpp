#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(int row, int col, vector<vector<int>> &vis, int** arr, int n, int m, vector<pair<int,int>> &vec, int row0, int col0) {
    vis[row][col] = 1;
    vec.push_back({row - row0, col - col0});

    int drow[] = {0, 1, 0, -1};
    int dcol[] = {-1, 0, 1, 0};

    for (int i = 0; i < 4; i++) {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && arr[nrow][ncol]) {
            dfs(nrow, ncol, vis, arr, n, m, vec, row0, col0);
        }
    }
}

int distinctIslands(int** arr, int n, int m) {
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>> > st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && arr[i][j]) {
                vector<pair<int, int>> vec;
                dfs(i, j, vis, arr, n, m, vec, i, j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}

int main() {
    int n = 4;
    int m = 5;
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }

    // Initialize the array
    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[0][2] = 0;
    arr[0][3] = 0;
    arr[0][4] = 0;
    arr[1][0] = 1;
    arr[1][1] = 1;
    arr[1][2] = 0;
    arr[1][3] = 0;
    arr[1][4] = 0;
    arr[2][0] = 0;
    arr[2][1] = 0;
    arr[2][2] = 0;
    arr[2][3] = 1;
    arr[2][4] = 1;
    arr[3][0] = 0;
    arr[3][1] = 0;
    arr[3][2] = 0;
    arr[3][3] = 1;
    arr[3][4] = 1;

    cout << distinctIslands(arr, n, m) << endl;


    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
