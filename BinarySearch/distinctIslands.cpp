#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int, int>>& shape, 
    int row0, int col0, vector<int>& drow, vector<int>& dcol) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        shape.push_back({row - row0, col - col0});

        for(int i=0; i<4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol] and grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, vis, shape, row0, col0, drow, dcol);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, -1, 0, 1};
        set<vector<pair<int, int>>> st;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] and grid[i][j] == 1) {
                    vector<pair<int, int>> shape;
                    dfs(i, j, grid, vis, shape, i, j, drow, dcol);
                    st.insert(shape);
                }
            }
        }
        return st.size();
    }
};

int main() {
    vector<vector<int>> grid = {{1,1,0,0,0}, {1,1,0,0,0}, {0,0,1,1}, {0,0,1,1}};
    Solution S;
    cout << S.countDistinctIslands(grid) << endl;
    return 0;
}