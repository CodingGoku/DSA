#include <bits/stdc++.h>
using namespace std;

// T : (E)logV + V ... logV for each insertion in pq, V for determining path
// S : V
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // priority queue (min heap)
    vector<int> dist(V, 1e9);

    vector<int> parent(V);
    for(int i=0; i<V; i++) parent[i] = i; // initially parent of a node is itself

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

                //update the parent
                parent[adjNode] = node; // node -> adjNode
            }
        }
    }

    // if we cannot reach the last node
    if(dist[V-1] == 1e9) return {-1};

    vector<int> path;

    // get the path from last node to the first i.e. in reverse
    int node = V-1; // last node
    while(parent[node] != node) { // parent of starting node is itself
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(S); // starting node is not inserted in while loop

    // reverse the path to get from source -> destination
    reverse(path.begin(), path.end());

    return path;
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
    cout<<"path from Source to Destination : ";
    for(int i : dist) cout<<i<<" ";

    V = 6, S = 1;
    // u -> {{v,w},{v,w}}
    adj[0] = {};
    adj[1] = {{2,2},{4,1}};
    adj[2] = {{1,2},{3,4},{5,5}};
    adj[3] = {{2,4},{4,3},{5,1}};
    adj[4] = {{1,1},{3,3}};
    adj[5] = {{2,5},{3,1}};

    dist = dijkstra(V, adj, S);
    cout<<"\n\npath from Source to Destination : ";
    for(int i : dist) cout<<i<<" ";
    return 0;
}