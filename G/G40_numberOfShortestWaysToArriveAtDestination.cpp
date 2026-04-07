#include <bits/stdc++.h>
using namespace std;

// T : E logV ... same as Dijkstra
// S : V
int numberOfWays(int V, vector<vector<int>>& roads) {
    vector<pair<int, int>> adj[V];

    for(auto it : roads) {
        adj[it[0]].push_back({it[1],it[2]}); // u -> {v,wt}
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,0}); // dist, node

    vector<int> dist(V,1e9), ways(V,0);
    dist[0]=0;
    ways[0]=1; // one way to reach node 0

    while(!pq.empty()) {
        int distance = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for(auto it : adj[u]) {
            int v = it.first;
            int wt = it.second;

            if(dist[v] > distance + wt) { // we have got better way to reach v, through u
                ways[v] = ways[u]; // if we can reach u through x ways, then we can reach v through x ways
                dist[v] = distance + wt;
                pq.push({dist[v],v});
            }
            else if(dist[v] == distance + wt) { // we have got another way with same cost to reach v
                ways[v] += ways[u]; // if we can reach u through x ways, then we can reach v through x ways
                // no need to push to pq, as it is already in pq with that {dist ,node}
            }
        }
    }

    if(ways[V-1] == 0) return -1; // no way to reach
    return ways[V-1];
}

int main()
{
    vector<vector<int>> roads = {{0,1,1},
                                 {0,2,2},
                                 {0,3,1},
                                 {0,4,2},
                                 {1,5,2},
                                 {2,5,1},
                                 {3,5,2},
                                 {3,7,3},
                                 {3,6,2},
                                 {4,6,1},
                                 {5,8,1},
                                 {7,8,1},
                                 {6,8,1}};
    
    int V = 9;
    cout<<"number of ways : "<<numberOfWays(V, roads);
    return 0;
}