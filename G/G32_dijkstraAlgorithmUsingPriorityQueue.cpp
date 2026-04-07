#include <bits/stdc++.h>
using namespace std;

// T : (E)logV ... logV for each insertion in priority queue
// S : V
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // priority queue (min heap)
    vector<int> dist(V, 1e9);

    dist[S] = 0; // dist from source is 0
    pq.push({0,S}); // dist, node

    while(!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]) {
            int edgeWeight = it[1];
            int adjNode = it[0];

            if(dis + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main()
{
    int V = 6, S = 0;
    vector<vector<int>> adj[V];
    // u -> {{v,w},{v,w}}
    adj[0] = {{1,4},{2,4}};
    adj[1] = {{0,4},{2,2}};
    adj[2] = {{0,4},{1,2},{3,3},{4,1},{5,6}};
    adj[3] = {{2,3},{5,2}};
    adj[4] = {{2,1},{5,3}};
    adj[5] = {{3,2},{2,6},{4,3}};

    vector<int> dist = dijkstra(V, adj, S);
    cout<<"dist : ";
    for(int i : dist) cout<<i<<" ";
    return 0;
}