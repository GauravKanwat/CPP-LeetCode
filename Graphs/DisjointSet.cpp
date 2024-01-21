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

    //path compression
    int findUPar(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    //Union by Rank
    void unionByRank(int u, int v) {
        int ult_p_u = findUPar(u);
        int ult_p_v = findUPar(v);
        
        //if in same component
        if(ult_p_u == ult_p_v) return;

        if(rank[ult_p_u] > rank[ult_p_v])
            parent[ult_p_v] = ult_p_u;
        else if(rank[ult_p_u] < rank[ult_p_v])
                parent[ult_p_u] = ult_p_v;
        else {
            parent[ult_p_u] = ult_p_v;
            rank[ult_p_v]++;
        }
    }

    void unionBySize(int u, int v) {
        int ult_p_u = findUPar(u);
        int ult_p_v = findUPar(v);

        //if in same component
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

int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    //if 3 and 7 belongs to the same components or not
    if(ds.findUPar(3) == ds.findUPar(7)) cout << "Same" << endl;
    else cout << "Different" << endl;
    ds.unionBySize(3, 7);
    if(ds.findUPar(3) == ds.findUPar(7)) cout << "Same" << endl;
    else cout << "Different" << endl;
    return 0;
}