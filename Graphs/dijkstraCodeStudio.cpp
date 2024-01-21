#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> adjList[], int vertices) {
    for(int i=0; i<vertices; i++) {
        cout << "vertex " << i << ": ";
        for(auto j : adjList[i]) {
            for(auto k : j) {
                cout << k << " ";
            }
        }
        cout << endl;
    }
}

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    // Write your code here.
    // 'edge' contains {u, v, distance} vectors.
    vector<vector<int>> adjList[vertices];

    for(int i=0; i<edge.size(); i++) {
      adjList[edge[i][0]].push_back({edge[i][1], edge[i][2]});

      adjList[edge[i][1]].push_back({edge[i][0], edge[i][2]});
    }

    set<pair<int, int>> st;
    vector<int> dist(vertices, 1e9);
    dist[source] = 0;
    st.insert({dist[source], source});

    while(!st.empty()) {
        auto it = *(st.begin());
        int node = it.second;
        int d = it.first;
        st.erase(it);

        for(auto i : adjList[node]) {
            int edgeWeight = i[1];
            int adjNode = i[0];

            if(dist[adjNode] > d + edgeWeight) {
                dist[adjNode] = d + edgeWeight;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main()
{
    vector<vector<int>> edge = {{0,1,5},{0,2,8},{1,2,9},{1,3,2},{2,3,6}};
    int vertices = 4;
    int edges = 5;
    int source = 0;
    vector<int> result = dijkstra(edge, vertices, edges, source);
    for(auto i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}