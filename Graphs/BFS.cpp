#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> BFSTraversal(int V, vector<int> adj[]) {
        int vis[V] = {0};
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
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
        return bfs;
    }
};

int main() {
    int V = 9;
    vector<int> result;
    vector<int> adj[V+1];
    Solution S;
    result = S.BFSTraversal(6, adj);
}