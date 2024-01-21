#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int, int>> st;
        st.insert({0, S});
        vector<int> dist(V, 1e9);
        dist[S] = 0;

        while(!st.empty()) {
            auto it = *(st.begin());
            int node = it.second;
            int d = it.first;
            st.erase(it);

            for(auto i : adj[node]) {
                int edgeWeight = i[1];
                int adjNode = i[0];

                if(dist[adjNode] > d + edgeWeight) {
                    if(dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});
                    dist[adjNode] = d + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }

int main()
{
    vector<vector<int>> adj[] = {{{1, 9}}, {{0, 9}}};
    int V = 2, S = 0;
    vector<int> result = dijkstra(V, adj, S);
    for(auto i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}