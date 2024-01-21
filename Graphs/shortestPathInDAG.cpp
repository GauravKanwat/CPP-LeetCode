#include<bits/stdc++.h>
using namespace std;

void dfs(int source, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st) {
    vis[source] = 1;

    for(auto i : adj[source]) {
        int adjNode = i.first;

        if(!vis[adjNode]) dfs(adjNode, adj, vis, st);
    }

    st.push(source);
}

vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    //create the graph
    vector<pair<int, int>> adj[N];
    for(int i=0; i<M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    //find the topo sort
    vector<int> vis(N, 0);
    stack<int> st;
    for(int i=0; i<N; i++) {
        if(!vis[i]) dfs(i, adj, vis, st);
    }

    //create the distance array initialized with max value
    vector<int> dist(N, 1e9);
    dist[0] = 0;

    while(!st.empty()) {
        int node = st.top();
        st.pop();

        for(auto i : adj[node]) {
            int adjNode = i.first;
            int edgeWeight = i.second;

            //perform relaxation
            if(dist[adjNode] > edgeWeight + dist[node]) {
                dist[adjNode] = edgeWeight + dist[node];

            }
        }
    }
    return dist;
}


int main()
{
    int n = 6, m = 7;
    vector<vector<int>> edges = {{0,1,2}, {0,4,1},{4,5,4}, {4,2,2}, {1,2,3}, {2,3,6}, {5,3,1}};
    vector<int> result = shortestPath(n, m, edges);
    for(auto i : result) cout << i << " ";
    cout << endl;
    return 0;
}