#include<bits/stdc++.h>
using namespace std;

class Graph {
    private:
    bool dfs(int node, int parent, vector<int> adj[], vector<int> vis) {
        vis[node] = 1;
        for(auto adjNode : adj[node]) {
            if(!vis[adjNode]) {
                if(dfs(adjNode, node, adj, vis) == true) return true;
            }
            else if(adjNode != parent) return true;
        }
        return false;
    }
    public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(dfs(i, -1, adj, vis) == true) return true;
            }
        }
        return false;
    }
};

int main() {
    int V = 5;
    vector<int> adj[] = {{1}, {0,2,4}, {1,3}, {2,4}, {1,3}};
    Graph G;
    bool cycle = G.isCycle(V, adj);
    cout << cycle << endl;
    return 0;
}