#include<iostream>
using namespace std;

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    vector<vector<int>> graph(n);
    for(int i=0; i<edges.size(); i++) {
        graph[edges[1][i]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[1][i]);
    }

    vector<vector<int>> adjList(n);
    for(int i=0; i<n; i++) {
        adjList[i].push_back(i);
        for(int j=0; j<graph[i].size(); j++) {
            adjList[i].push_back(graph[i][j]);
        }
    }
    return adjList;
}

int main()
{
    int n = 3, m = 2;
    vector<vector<int>> edges = {{2,1}, {2,0}};
    vector<vector<int>> result = printAdjacency(n, m, edges);
    for(auto i : result) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}