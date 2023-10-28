#include<iostream>
using namespace std;


int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<int> prev(m, 0);
    for(int i=0; i<n; i++) {
        vector<int> temp(m, 0);
        for(int j=0; j<m; j++) {
            if(mat[i][j] == -1) temp[j] = 0;
            else if(i == 0 and j == 0) temp[j] = 1;
            else {
                int up = 0, left = 0;
                if(i > 0) up = prev[j];
                if(j > 0) left = temp[j-1];
                temp[j] = up + left;
            }
        }
        prev = temp;
    }
    return prev[m-1];
}

int main()
{
    int n = 3, m = 3;
    vector<vector<int>> matrix = {{0,0,0}, {0,-1,0}, {0,0,0}};
    cout << mazeObstacles(n, m, matrix) << endl;
    return 0;
}