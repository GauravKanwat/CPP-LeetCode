#include<bits/stdc++.h>
using namespace std;

class Graph {
    private:
    void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st) {
        vis[node] = 1;

        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }
    public:
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
        vector<int> vis(V, 0);
        stack<int> st;

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
	}
};

int main() {
    int V = 6;
    vector<int> adj[] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    vector<int> result;
    Graph G;
    result = G.topoSort(V, adj);
    for(int i : result) cout << i << " ";
    cout << endl;
    return 0;
}