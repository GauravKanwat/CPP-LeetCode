#include<bits/stdc++.h>
using namespace std;

class Graph {
    private:
    bool check(int start, int V, vector<int> adj[], int color[]) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        // vector<int> color(V, -1);
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it : adj[node]) {
                //Not colored initially
                if(color[it] == -1) {
                    if(color[node] == 0) color[it] = 1;
                    else color[it] = 0;
                    q.push(it);
                }
                //Check if they have same color
                else if(color[it] == color[node]) return false;
            }
        }
        return true; 
    }
    public:
    bool isBipartite(int V, vector<int> adj[]) {
        int color[V];
        for(int i=0; i<V; i++) color[i] = -1;
        for(int i=0; i<V; i++) {
            if(color[i] == -1) {
                if(check(i, V, adj, color) == false) return false;
            }
        }
        return true;
    }
};

int main() {
    int V = 3;
    vector<int> adj[] = {{1}, {0, 2}, {1}};
    Graph G;
    bool isBip = G.isBipartite(V, adj);
    cout << isBip << endl;
    return 0;
}