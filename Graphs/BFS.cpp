#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void bfs(int node, int V, vector<int> adj[], vector<int> &vis, vector<int> bfs) {
        vis[node] = 1;
        queue<int> q;
        q.push(1);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    public:
    vector<int> BFSTraversal(int V, vector<int> adj[]) {
        vector<int> bfs;
        vector<int> vis(V, 0);

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                bfs(i, V, adj, vis, bfs);
            }
        }
    }
};

int main() {
    int V = 9;
    vector<int> result;
    vector<int> adj[] = {{}, {2, 6}, {1, 3, 4}, {2}, {2, 5}, {4, 7}, {1, 7, 8}, {5, 6}, {6}};
    Solution S;
    result = S.BFSTraversal(V, adj);
    for(auto i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}