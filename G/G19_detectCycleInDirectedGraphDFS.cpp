#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], vector<int> &vis, vector<int> &pathVis, int node) {
    vis[node] = 1;
    pathVis[node] = 1;

    for(int neighbour : adj[node]) {
        if(!vis[neighbour]) { // node not visited
            if(dfs(adj, vis, pathVis, neighbour)) return true;
        }
        else if(pathVis[neighbour]) return true; // node visited and path also visited ... it's a loop
        // if it is visited and not path visited, we do not need to traverse it as it is already checked for loop
    }

    // backtracking
    pathVis[node] = 0;

    return false;
}

// T : O(V + E) ... as it is directed graph
// S : O(2V)
bool isCycle(int V, vector<int>adj[]) {
    vector<int> vis(V+1,0);
    vector<int> pathVis(V+1,0);

    for(int i=1; i<=V; i++) {
        if(!vis[i]) {
            if(dfs(adj, vis, pathVis, i)) return true;
        }
    }
    return false;
}

int main()
{
    int V = 10;
    vector<int> adj[V+1];
    adj[0] = {};
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {4,7};
    adj[4] = {5};
    adj[5] = {6};
    adj[6] = {};
    adj[7] = {5};
    adj[8] = {2,9};
    adj[9] = {10};
    adj[10] = {8};

    cout<<"isCycle : "<<isCycle(V, adj);
    return 0;
}