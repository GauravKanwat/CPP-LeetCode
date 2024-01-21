#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
    public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }

    //compression
    int findUPar(int node) {
        if(parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    //union by rank
    void unionByRank(int u, int v) {
        int ult_p_u = findUPar(u);
        int ult_p_v = findUPar(v);

        //same
        if(ult_p_u == ult_p_v) return;

        if(rank[ult_p_u] > rank[ult_p_v])
            parent[ult_p_v] = ult_p_u;
        else if(rank[ult_p_v] > rank[ult_p_u])
            parent[ult_p_u] = ult_p_v;
        else {
            parent[ult_p_u] = ult_p_v;
            rank[ult_p_v]++;
        }
    }

    //union by size
    void unionBySize(int u, int v) {
        int ult_p_u = findUPar(u);
        int ult_p_v = findUPar(v);

        //same
        if(ult_p_u == ult_p_v) return;

        if(size[ult_p_u] > size[ult_p_v]) {
            parent[ult_p_v] = ult_p_u;
            size[ult_p_u] += size[ult_p_v];
        }
        else {
            parent[ult_p_u] = ult_p_v;
            size[ult_p_v] += size[ult_p_u];
        }
    }
};

int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int, int>>> edges;

        for(int i=0; i<V; i++) {
            for(auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }

        DisjointSet ds(V);

        sort(edges.begin(), edges.end());
        int mstWt = 0;
        for(auto i : edges) {
            int wt = i.first;
            int u = i.second.first;
            int v = i.second.second;

            if(ds.findUPar(u) != ds.findUPar(v)) {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }
        return mstWt;
    }

int main()
{
    
    return 0;
}