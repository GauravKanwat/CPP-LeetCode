#include<iostream>
using namespace std;


int main()
{
    int n, m;
    cin >> n >> m;

    //Using matrix
    // int adj[n+1][m+1];
    // for(int i=0; i<m; i++) {
    //     int u, v;
    //     cin >> u >> v;
    //     adj[u][v] = 1;
    //     adj[v][u] = 1;
    // }

    //Using AdjList
    vector<int> adjList[n+1];
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return 0;
}