#include <bits/stdc++.h>
using namespace std;

// T : E = flights.size() ... not E x logV as logV was for priority queue which we are not using here
// S : V
int cheapestFlights(int V, vector<vector<int>>& flights, int src, int dst, int k) { // k -> max stops
    vector<pair<int, int>> adj[V];
    for(auto it : flights) {
        adj[it[0]].push_back({it[1], it[2]}); // u -> {v, w}
    }

    vector<int> dist(V,1e9);
    dist[src] = 0;

    queue<pair<int, pair<int, int>>> q; // stops, node, dist
    q.push({0,{src,0}});

    while(!q.empty()) {
        int stops = q.front().first;
        int node = q.front().second.first;
        int distance = q.front().second.second;
        q.pop();

        if(stops > k) continue;

        for(auto i : adj[node]) {
            int v = i.first;
            int wt = i.second;

            if(distance + wt < dist[v]) {
                dist[v] = distance + wt;
                q.push({stops+1,{v,dist[v]}});
            }
        }
    }

    if(dist[dst] == 1e9) return -1;

    return dist[dst];
}

int main()
{
    vector<vector<int>> flights = {{0,1,5},
                                   {0,3,2},
                                   {1,2,5},
                                   {1,4,1},
                                   {3,1,2},
                                   {4,2,1}};
    
    int V = 5;
    cout<<"cheapest flight with k stops cost : "<<cheapestFlights(V,flights,0,2,2);
    return 0;
}