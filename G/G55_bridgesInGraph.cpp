#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int>& vis, vector<int> adj[], int tin[], int low[], vector<vector<int>>& bridges) {
    vis[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    for(auto it : adj[node]) {
        if(it == parent) continue; // cannot go back to parent
        if(vis[it] == 0) {
            dfs(it,node,vis,adj,tin,low,bridges);
            low[node]=min(low[node],low[it]);
            // check for bridge
            if(low[it] > tin[node]) {
                bridges.push_back({it, node});
            }
        }
        else {
            low[node] = min(low[node], low[it]);
        }
    }
}

// T : V+2E
// S : (V+2E) + 3V
vector<vector<int>> criticalConnections(int V, vector<vector<int>>& connections) {
    vector<int> adj[V+1]; // 1-based indexing
    for(auto it: connections) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(V+1,0); // i-based indexing
    int tin[V];
    int low[V];
    vector<vector<int>> bridges;
    dfs(1,-1,vis, adj, tin, low, bridges);
    return bridges;
}

int main()
{
    int V = 13;
    vector<vector<int>> connections = {{1,2},{2,3},{3,4},{4,1},{4,5},{5,6},{6,7},
                                       {7,8},{8,9},{9,6},{8,10},{10,11},{11,12},{12,10}};
    vector<vector<int>> bridges = criticalConnections(V, connections);
    for(auto i : bridges) {
        for(auto j : i) cout<<j<<" ";
        cout<<"\n";
    }
    return 0;
}