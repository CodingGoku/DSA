#include <bits/stdc++.h>
using namespace std;

// using floyd warshall
// T : N x N x N
// S : N x N
int cityWithSmallestNoOfNeighbours(int V, vector<vector<int>>& edges, int thresholdDistance) {

    vector<vector<int>> weights (V, vector<int>(V,1e9)); // initially weights is high assuming we cannot visit first
    for(auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        // graph is bidirectional
        weights[u][v] = wt;
        weights[v][u] = wt;
    }

    // diagonal ... most important ... don't ever miss it
    for(int i=0; i<V; i++) weights[i][i] = 0;

    // apply floyd warshall
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            for(int k=0; k<V; k++) {
                weights[i][j] = min(weights[i][j], weights[i][k] + weights[k][j]);
            }
        }
    }

    // print matrix
        for(auto i : weights) {
            cout<<"[";
            for(auto j : i) cout<<j<<" ";
            cout<<"]\n";
        }

    int mini = INT_MAX;
    int cityWithSmallestNoOfNeighbours;
    for(int i=0; i<V; i++) {
        int cities = 0;
        for(int j=0; j<V; j++) {
            if(weights[i][j] <= thresholdDistance) cities++;
        }
        
        if(cities <= mini) { // as the question states that if there are multiple cities with smallest no. of neighbours
            mini = cities;  // return the last/hightest city i.e.w. we have used `=`
            cityWithSmallestNoOfNeighbours = i;
        }
    }

    return cityWithSmallestNoOfNeighbours;
}

// using djikstra
// T : V x E(logV) ... extra V for V different source(S) each time ... applying dijkstra V-times
// S: V x V
int cityWithNeighbours(int V, vector<vector<int>>& edges, int threshold) {
    vector<pair<int, int>> adj[V];
    for(auto it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
    }

    int mini = INT_MAX;
    int city;

    // for V different source(S) each time
    for(int i=0; i<V; i++) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V,1e9);
        pq.push({0,i}); // dist, node(source)
        dist[i] = 0; // distance of source is 0

        while(!pq.empty()) {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                if(distance + wt < dist[v]) {
                    dist[v] = distance + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        int cnt = 0;
        for(auto i : dist) {
            if(i <= threshold) cnt++;
        }
        
        if(cnt <= mini) {
            mini = cnt;
            city = i;
        }
    }
    return city;
}

int main()
{
    vector<vector<int>> edges = {{0,1,3},
                                 {1,2,1},
                                 {1,3,4},
                                 {2,3,1}};
    
    int V = 4;
    int city = cityWithSmallestNoOfNeighbours(V, edges, 4);
    cout<<"\ncity : "<<city;

    city = cityWithNeighbours(V, edges, 4);
    cout<<"\n\ncity : "<<city;
    return 0;
}