#include <bits/stdc++.h>
using namespace std;

// T : E(logV)
// S : V
int spanningTree(int V, vector<vector<int>> adj[]) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,0}); // wt, node

    int vis[V] = {0};

    int sum = 0;
    while(!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(vis[node] == 1) continue;
        // if not visited add to MST
        vis[node] = 1;
        sum += wt;
        for(auto it : adj[node]) {
            int adjNode = it[0];
            int adjwt = it[1];

            if(!vis[adjNode]) pq.push({adjwt, adjNode});
        }
    }
    return sum;
}

int main()
{
    int V = 5;
    // {u,v,w}
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    cout<<"sum : "<<spanningTree(V, adj);
    return 0;
}