#include <bits/stdc++.h>
using namespace std;

// T : O(V + 2E)
// S : O(V)
vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
    vector<int> adj[N];
    for(int i=0; i<M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v); // u -> v
        adj[v].push_back(u); // v -> u
    }

    vector<int> dist(N, 1e9);
    queue<int> q; // node
    q.push(src); // starting at node `src` with dist = 0
    dist[src] = 0;


    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int neighbour : adj[node]) {
            if(dist[node] + 1 < dist[neighbour]) {
                dist[neighbour] = dist[node] + 1;
                q.push(neighbour); // only pushing when we are getting lesser value
            }
        }
    }

    // if not able to reach a node from the given src
    for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
    }

    return dist;
}

int main()
{
    vector<vector<int>> edges = {{0,1},{0,3},{1,2},{3,4},{4,5},{5,6},{2,6},{6,7},{6,8},{7,8}};
    int N = 9; // vertices
    int M = 10; // edges
    int src = 0;
    vector<int> dist = shortestPath(edges, N, M, src);
    cout<<"dist : ";
    for(int i : dist) cout<<i<<" ";
    return 0;
}