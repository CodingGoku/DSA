#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], vector<int> &vis, vector<int> &pathVis, int node, int check[]) {
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0; // inititally all are set as loop

    for(int neighbour : adj[node]) {
        if(!vis[neighbour]) { // node not visited
            if(dfs(adj, vis, pathVis, neighbour, check)) {
                check[node] = 0; // is loop ... no need for this line as already initialized
                return true; 
            }
        }
        else if(pathVis[neighbour]) {
            check[node] = 0; // is loop ... no need for this line as already initialized
            return true; // node visited and path also visited ... it's a loop
        }
    }

    // if we reach till here then it's not a loop ... i.e. if we are able to visit all neighbours of node
    check[node] = 1;

    // backtracking
    pathVis[node] = 0;

    return false;
}

// T : O(V + E) ... as it is directed graph
// S : O(3V)
vector<int> safeStates(int V, vector<int>adj[]) {
    vector<int> vis(V+1,0);
    vector<int> pathVis(V+1,0);
    int check[V+1];

    for(int i=1; i<=V; i++) {
        if(!vis[i]) {
            dfs(adj, vis, pathVis, i, check);
        }
    }

    vector<int> safe;
    for(int i=1; i<=V; i++) {
        if(check[i]) safe.push_back(i); // push the safe nodes
    }

    return safe;
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

    vector<int> safe = safeStates(V, adj);
    for(int i : safe) cout<<i<<" ";
    return 0;
}