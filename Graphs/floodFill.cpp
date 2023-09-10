#include<bits/stdc++.h>
using namespace std;

class Graph {
    private:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int newColor, int iniColor, int delRow[], int delCol[]) {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i=0; i<4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and image[nrow][ncol] == iniColor and ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, ans, image, newColor, iniColor, delRow, delCol);
            }
        }
    }
    public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        dfs(sr, sc, ans, image, newColor, iniColor, delRow, delCol);
        return ans;
    }
};

int main() {
    vector<vector<int>> image = {{1,1,1}, {1,1,0},{1,0,1}};
    int sr = 1, sc = 1, newColor = 2;
    Graph G;
    vector<vector<int>> result;
    result = G.floodFill(image, sr, sc, newColor);
    for(int i=0; i<result.size(); i++) {
        for(int j=0; j<result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}