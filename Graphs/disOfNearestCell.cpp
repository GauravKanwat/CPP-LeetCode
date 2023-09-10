#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
    vector<vector<int>> nearest(vector<vector<int>> grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
                else vis[i][j] = 0;
            }
        }
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps;

            for(int i=0; i<4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps + 1});
                }
            }
        }
        return dist;
    }
};

int main() {
    vector<vector<int>> grid = {{1,0,1},{1,1,0},{1,0,0}};
    vector<vector<int>> result;
    Graph G;
    result = G.nearest(grid);
    for(int i=0; i<result.size(); i++) {
        for(int j=0; j<result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}