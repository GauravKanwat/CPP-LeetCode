#include<bits/stdc++.h>
using namespace std;

class Graph {
    private:
    bool detect(int src, vector<int> adj[], vector<int> vis) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});

        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto adjacentNode : adj[node]) {
                if(!vis[adjacentNode]) {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                else if(adjacentNode != parent) {
                    return true;
                }
            }
        }
        return false;
    }
    public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(detect(i, adj, vis)) return true;
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
}