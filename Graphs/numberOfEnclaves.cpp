#include<bits/stdc++.h>
using namespace std;

class Graph {
    private:
    void dfs(int row, int col, vector<vector<int>> grid, vector<vector<int>> &vis, int drow[], int dcol[]) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol] and grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, vis, drow, dcol);
            }
        }
    }
    public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int j=0; j<m; j++) {
            if(!vis[0][j] and grid[0][j] == 1) {
                dfs(0, j, grid, vis, drow, dcol);
            }
            if(!vis[n-1][j] and grid[n-1][j] == 1) {
                dfs(n-1, j, grid, vis, drow, dcol);
            }
        }
        for(int i=0; i<n; i++) {
            if(!vis[i][0] and grid[i][0] == 1) {
                dfs(i, 0, grid, vis, drow, dcol);
            }
            if(!vis[i][m-1] and grid[i][m-1] == 1) {
                dfs(i, m-1, grid, vis, drow, dcol);
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] and grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main() {
    vector<vector<int>> grid = {{0, 0, 0, 0},
                                {1, 0, 1, 0},
                                {0, 1, 1, 0},
                                {0, 0, 0, 0}};
    Graph G;
    int enclaves = G.numberOfEnclaves(grid);
    cout << enclaves << endl;
    return 0;
}