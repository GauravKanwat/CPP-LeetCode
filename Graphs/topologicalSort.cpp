#include<bits/stdc++.h>
using namespace std;

class Graph {
    private:
    void dfs(vector<int> graph[], int source, stack<int> &st ,vector<int> &vis) {
        vis[source] = 1;
        
        for(auto i : graph[source]) {
            if(!vis[i]) dfs(graph, i, st, vis);
        }

        st.push(source);
    }

    public:
    vector<int> topoSort(int V, vector<int> graph[]) {
    stack<int> st;
    vector<int> vis(V, 0);
    for(int i=0; i<V; i++) {
        if(!vis[i]) dfs(graph, i, st, vis);
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
    vector<int> adj[] = {{}, {3}, {3}, {}, {0,1}, {0,2}};
    vector<int> result;
    Graph G;
    result = G.topoSort(6, adj);
    for(int i : result) cout << i << " ";
    cout << endl;
    return 0;
}