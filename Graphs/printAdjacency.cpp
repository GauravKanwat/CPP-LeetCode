#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<int>> adjList(n);
    for(int i=0; i<n; i++) {
        adjList[i].push_back(i);
    }
    for(int i=0; i<m; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    for (int i = 0; i < m; i++)
    {
        int c, v;
        cin >> c >> v;
        edges[c].push_back(v);
    }
    printAdjacency(n, m, edges);
}