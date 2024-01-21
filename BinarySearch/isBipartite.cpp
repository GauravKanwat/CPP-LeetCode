#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(int node, int V, vector<vector<int>>& graph, vector<int> &color) {
        queue<int> q;
        q.push(node);
        color[node] = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto adjNode : graph[node]) {
                if(color[adjNode] == -1) {
                    color[adjNode] = !color[node];
                    q.push(adjNode);
                }
                else if(color[adjNode] == color[node]) 
                    return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        for(int i=0; i<V; i++) {
            if(color[i] == -1) 
                if(check(i, V, graph, color) == false)
                    return false;
        }
        return true;
    }
};

int main() {
    Solution S;
    vector<vector<int>> graph = {{1,2,3}, {0,2}, {0,1,3}, {0,2}};
    if(S.isBipartite(graph)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}