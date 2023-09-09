#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs(int node, vector<int> adj[], vector<int> &vis) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }
    public:
    int findNumOfProvinces(vector<vector<int>> adj, int V) {
        //change adj matrix to list
        vector<int> adjLs[V];
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                } 
            }
        }
        vector<int> vis(V, 0);
        int cnt = 0;
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> roads(n, vector<int> (n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> roads[i][j];
        }
    }
    Solution S;
    int provinces;
    provinces = S.findNumOfProvinces(roads, n);
    cout << provinces << endl;
    return 0;
}