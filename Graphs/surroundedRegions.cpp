#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void traverse(int row, int col, vector<vector<char>>& board, vector<vector<int>> &vis, 
    vector<int> &drow, vector<int> &dcol) {
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;

        for(int i=0; i<4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and vis[nrow][ncol] == 0 and board[nrow][ncol] == 'O') {
                traverse(nrow, ncol, board, vis, drow, dcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, -1, 0, 1};

        //traverse rows
        for(int j=0; j<m; j++) {
            if(!vis[0][j] and board[0][j] == 'O') {
                traverse(0, j, board, vis, drow, dcol);
            }
            if(!vis[n-1][j] and board[n-1][j] == 'O') {
                traverse(n-1, j, board, vis, drow, dcol);
            }
        }
        
        //traverse columns
        for(int i=0; i<n; i++) {
            if(!vis[i][0] and board[i][0] == 'O') {
                traverse(i, 0, board, vis, drow, dcol);
            }
            if(!vis[i][m-1] and board[i][m-1] == 'O') {
                traverse(i, m-1, board, vis, drow, dcol);
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'O' and vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main() {
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, 
                                  {'X', 'O', 'O', 'X'}, 
                                  {'X', 'X', 'O', 'X'}, 
                                  {'X', 'X', 'X', 'X'}};
    Solution S;
    S.solve(board);
    for(auto i : board) {
        for(auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}