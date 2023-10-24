#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool isSafe(int row, int col, vector<string> &board, int n){
    int row1 = row;
    int col1 = col;

    // left upper diagonal 
    while(col>=0 && row>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        col--;
        row--;
    }

    col = col1;
    row = row1;
    
    // left side
    while(col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        col--;
    }

    col = col1;
    row = row1;
    
    // left lower diagonal
    while(row<n && col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row++;
        col--;
    }

    return true;
}





void Solve(int col, vector<vector<string>> &ans, vector<string> &board, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            Solve(col + 1, ans, board, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> SolveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '*');

    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    Solve(0, ans, board, n);
    return ans;
}

int main()
{
    int n = 0;
    cout << "Print the size of the checkboard: " << endl;
    cin >> n;

    SolveNQueens(n);
   
    return 0;
}