#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;  // {{row, col}, time}
        int vis[n][m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else vis[i][j] = 0;
            }
        }
        int maxTime = 0;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            maxTime = max(maxTime, t);
            
            for(int i=0; i<4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and vis[nrow][ncol] != 2 and grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j] != 2 and grid[i][j] == 1) return -1;
            }
        }
        return maxTime;
    }

};

int main() {
    vector<vector<int>> grid = {{0,1,2}, {0,1,2}, {2,1,1}};
    Graph G;
    int numOfRottenOranges = G.orangesRotting(grid);
    cout << numOfRottenOranges << endl;
    return 0;
}