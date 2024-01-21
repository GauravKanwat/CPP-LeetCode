#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &edge, int V, int E, int source)
{
    // Write your code here.
    // 'edge' contains {u, v, distance} vectors.
    vector<vector<pair<int, int>>> adjLs(V);
    for(int i=0; i<V; i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        int w = edge[i][2];
        adjLs[u].push_back(make_pair(v, w));
        adjLs[v].push_back(make_pair(u, w));
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, 1e9);
    dist[source] = 0;
    pq.push({0, source});

    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto i : adjLs[node]) {
            int edgeWeight = i.first;
            int adjNode = i.second;

            if(dist[adjNode] > d + edgeWeight) {
                dist[adjNode] = d + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main()
{
    vector<vector<int>> edges = {{0,1,5}, {0,2,8}, {1,2,9}, {1,3,2}, {2,3,6}};
    int V = 4, E = 5;
    vector<int> result = dijkstra(edges, V, E, 0);
    for(auto i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}