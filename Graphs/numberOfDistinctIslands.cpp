#include<bits/stdc++.h>
using namespace std;

class Graph {
    private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &vis, vector<pair<int, int>> &vec, int brow, int bcol) {
        vis[row][col] = 1;
        vec.push_back({row - brow, col - bcol});
        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for(int i=0; i<4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and 
            !vis[nrow][ncol] and grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, vis, vec, brow, bcol);
            }
        }
    }
    public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        set<vector<pair<int, int>>> st;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1 and !vis[i][j]) {
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};

int main() {
    vector<vector<int>> grid = {{1, 1, 0, 0, 0},
                                {1, 1, 0, 0, 0},
                                {0, 0, 0, 1, 1},
                                {0, 0, 0, 1, 1}};
    Graph G;
    int distintIslands = G.countDistinctIslands(grid);
    cout << distintIslands << endl;
    return 0;
}