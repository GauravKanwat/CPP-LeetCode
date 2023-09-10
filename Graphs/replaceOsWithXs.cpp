#include<bits/stdc++.h>
using namespace std;

class Graph {
    private:
    void dfs(int row, int col, vector<vector<char>> &mat, vector<vector<int>> &vis, int drow[], int dcol[]) {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0; i<4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol] and mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, mat, vis, drow, dcol);
            }
        }
    }
    public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int j=0; j<m; j++) {
            if(!vis[0][j] and mat[0][j] == 'O') {       //first row
                dfs(0, j, mat, vis, drow, dcol);
            }
            if(!vis[n-1][j] and mat[n-1][j] == 'O') {   //last row
                dfs(n-1, j, mat, vis, drow, dcol);
            }
        }

        for(int i=0; i<n; i++) {
            if(!vis[i][0] and mat[i][0] == 'O') {       //first column
                dfs(i, 0, mat, vis, drow, dcol);
            }
            if(!vis[i][m-1] and mat[i][m-1] == 'O') {     //last column
                dfs(i, m-1, mat, vis, drow, dcol);
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] and  mat[i][j] == 'O') {
                    vis[i][j] = 1;
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

int main() {
    int n = 5, m = 4;
    vector<vector<char>> mat = {{'X', 'X', 'X', 'X'}, 
                            {'X', 'O', 'X', 'X'},
                            {'X', 'O', 'O', 'X'},
                            {'X', 'O', 'X', 'X'},
                            {'X', 'X', 'O', 'O'}};
    vector<vector<char>> result;
    Graph G;
    result = G.fill(n, m, mat);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}