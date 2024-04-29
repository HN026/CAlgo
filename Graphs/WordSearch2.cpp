#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

  public:
    bool dfs(int row, int col, vector<vector<char>> &board, vector<vector<int>> &visited, string &word, int index) {
        visited[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        int len = word.size();
        if (board[row][col] != word[index]) {
            visited[row][col] = 0;
            return false;
        }
        if (index == len - 1)
            return true;

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol]) {
                if (dfs(nrow, ncol, board, visited, word, index + 1))
                    return true;
                ;
            }
        }

        visited[row][col] = 0;
        return false;
    }

    bool exist(vector<vector<char>> &board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (dfs(row, col, board, visited, word, 0))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << (sol.exist(board, word) ? "True" : "False") << endl;
    return 0;
}