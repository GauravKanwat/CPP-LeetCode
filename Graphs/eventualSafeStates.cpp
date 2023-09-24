#include <bits/stdc++.h>
using namespace std;

class Graph {
    private:
    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathvis, vector<int> &check) {
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;

        //traverse
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(dfs(it, adj, vis, pathvis, check)) {
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathvis[it]) {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }
    public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);
        vector<int> check(V, 0);
        vector<int> safeNodes;
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis, pathvis, check);
            }
        }
        for(int i=0; i<V; i++) {
            if(check[i] == 1) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};

int main() {
    int V = 12;
    vector<int> adj[] = {{1}, {2}, {3}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10}, {8}, {9}};
    Graph G;
    vector<int> result(V);
    result = G.eventualSafeNodes(V, adj);
    for(auto i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}