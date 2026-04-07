#include <bits/stdc++.h>
using namespace std;

// T : V x E
// S : V
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V,1e9);
    dist[S]=0; // without this you will face issues

    // perform relaxation N-1 times
    // V x E
    for(int i=0; i<V-1; i++) {
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // if it has no negative cycles then everyting should be relaxed after N-1 iterations
    // Nth iteration to check for Negative Cycles
    for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] + wt < dist[v]) {
                return {-1}; // Negative Cycle is present
            }
        }

    return dist;
}

int main()
{
    vector<vector<int>> edges = {{0,1,5},
                                 {1,2,-2},
                                 {1,5,-3},
                                 {2,4,3},
                                 {3,2,6},
                                 {3,4,-2},
                                 {5,3,1}};

    int V = 6;
    vector<int> dist = bellmanFord(V, edges, 0);
    for(auto it : dist) cout<<it<<" ";
    return 0;
}