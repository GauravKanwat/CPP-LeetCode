#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    // Write your code here.
    vector<int> adjList[n];
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    queue<pair<int, int>> Q;
    Q.push(make_pair(src, dist[src]));

    while(!Q.empty()) {
        int node = Q.front().first;
        int d = Q.front().second;
        Q.pop();

        for(auto i : adjList[node]) {
            if(dist[i] > d+1) {
                dist[i] = d+1;
                Q.push(make_pair(i, dist[i]));
            }
        }
    }
    return dist;
}

int main()
{
    int n = 5, m = 5;
    vector<vector<int>> edges = {{0,1},{1,4},{2,3},{2,4},{3,4}};
    int src = 1;
    vector<int> result = shortestPath(n, edges, src);
    for(auto i : result) cout << i << " ";
    cout << endl;
    return 0;
}