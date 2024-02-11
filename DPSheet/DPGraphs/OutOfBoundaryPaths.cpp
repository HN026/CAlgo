#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int dfs(int row, int col, int maxMove, int m, int n, vector<vector<vector<int>>> &dp){
    if(row<0 || row>=m || col<0 || col>= n) return 1;
    if(maxMove==0) return 0;

    if(dp[row][col][maxMove]!=-1) return dp[row][col][maxMove];
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    long long ways = 0;
    for(int i = 0; i<4; i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        ways += dfs(nrow, ncol, maxMove-1, m, n, dp)%MOD;
    }

    return dp[row][col][maxMove] = ways%MOD;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
   vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (maxMove+1, -1))); 
   return dfs(startRow, startColumn, maxMove, m, n, dp);
}

int main() {
    int m, n, maxMove, startRow, startColumn;

    cout << "Enter m, n, maxMove, startRow, startColumn: ";
    cin >> m >> n >> maxMove >> startRow >> startColumn;

    int result = findPaths(m, n, maxMove, startRow, startColumn);

    cout << "Number of paths: " << result << endl;

    return 0;
}
