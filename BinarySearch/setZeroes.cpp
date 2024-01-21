#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        stack<pair<int, int>> dimensions;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    dimensions.push({i, j});
                }
            }
        }
        while(!dimensions.empty()) {
            int row = dimensions.top().first;
            int col = dimensions.top().second;
            dimensions.pop();

            //take care of rows
            for(int j=0; j<m; j++) {
                matrix[row][j] = 0;
            }

            //take care of cols
            for(int i=0; i<n; i++) {
                matrix[i][col] = 0;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution S;
    S.setZeroes(matrix);
    for(auto it : matrix) {
        for(auto j : it) cout << j << " ";
        cout << endl;
    }
    return 0;
}