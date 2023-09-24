#include <bits/stdc++.h>
using namespace std;

class Graph {
    private:
    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        //traverse
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(dfs(it, adj, vis, pathVis) == true) return true;
            }
            else if(pathVis[it]) return true;
        }
        pathVis[node] = 0;
        return false;
    }
    public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(dfs(i, adj, vis, pathVis) == true) return true; 
            }
        }
        return false;
    }
};

int main() {
    int V = 4;
    vector<int> adj[] = {{1}, {2}, {3}, {3}};
    Graph G;
    cout << G.isCyclic(V, adj) << endl;
    return 0;
}