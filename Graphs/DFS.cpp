#include<bits/stdc++.h>
using namespace std;

class DFS {
    private:
    void dfs(int node, vector<int> adj[], vector<int> vis, vector<int> &ls) {
        vis[node] = 1;
        ls.push_back(node);
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, ls);
            }
        }
    }
    public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V);
        int start = 0;
        vector<int> ls;
        dfs(start, adj, vis, ls);
        return ls;
    }
};

int main() {
    int V = 10;
    vector<int> adj[V];
    for(int i=0; i<V; i++) {
        adj[i].push_back(i);
    }
    DFS dfs;
    vector<int> dfsResult;
    dfsResult = dfs.dfsOfGraph(V, adj);
    for(auto it : dfsResult) {
        cout << it << " ";
    }
    return 0;
}