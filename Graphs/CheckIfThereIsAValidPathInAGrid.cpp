#include <iostream>
#include <vector>

using namespace std;

int isValid(int i, int j, int a, int b) {
    // Up
    if (a == -1 && b == 0) {
        vector<vector<int>> check = {
            {}, {}, {2, 3, 4}, {}, {}, {2, 3, 4}, {2, 3, 4},
        };
        for (auto it : check[i]) {
            if (it == j)
                return true;
        }
    }

    // right
    if (a == 0 && b == 1) {
        vector<vector<int>> check {
            {}, {1, 3, 5}, {}, {}, {1, 3, 5}, {}, {1, 3, 5},
        };
        for (auto it : check[i]) {
            if (it == j)
                return true;
        }
    }
    
    // down
    if (a == 1 && b == 0) {
        vector<vector<int>> check {
            {}, {}, {2, 5, 6}, {2, 5, 6}, {2, 5, 6}, {}, {},
        };
        for (auto it : check[i]) {
            if (it == j)
                return true;
        }
    }

    // left
    if (a == 0 && b == -1) {
        vector<vector<int>> check {
            {}, {1, 4, 6}, {}, {1, 4, 6}, {}, {1, 4, 6}, {},
        };
        for (auto it : check[i]) {
            if (it == j)
                return true;
        }
    }

    return false;
}

void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
    int n = grid.size();
    int m = grid[0].size();
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    vis[row][col] = 1;

    for (int i = 0; i < 4; i++) {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            !vis[nrow][ncol] &&
            isValid(grid[row][col], grid[nrow][ncol], drow[i], dcol[i])) {
            dfs(nrow, ncol, grid, vis);
        }
    }
}

bool hasValidPath(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    dfs(0, 0, grid, vis);
    return vis[n - 1][m - 1] == 1;
}

int main() {
    vector<vector<int>> grid = {
        {2,4,3},
        {6,5,2}
    };
    bool result = hasValidPath(grid);
    cout << "Has valid path: " << (result ? "Yes" : "No") << endl;
    return 0;
}