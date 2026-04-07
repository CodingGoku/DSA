#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int node, int parent, vector<int> adj[], vector<int>& vis) {
    vis[node] = 1;

    for(int neighbour : adj[node]) {
        if(!vis[neighbour]) {
            if(detectCycle(neighbour, node, adj, vis)) return true;
        }
        else if(parent != neighbour) return true;
    }
    return false;
}

// T : O(N + 2E) + O(N) ... for connected components loop
// S : O(N)
bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V,0);

    // for connected components
    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            if(detectCycle(i, -1, adj, vis)) return true;
        }
    }
    return false;
}

int main()
{
    int n = 9;
    vector<int> adj[n];
    adj[0] = {};
    adj[1] = {2};
    adj[2] = {1,3};
    adj[3] = {2};
    adj[4] = {5};
    adj[5] = {4,6};
    adj[6] = {5};
    adj[7] = {8};
    adj[8] = {7};

    cout<<isCycle(n, adj)<<"\n";

    n = 4;
    adj[0] = {};
    adj[1] = {2,3};
    adj[2] = {1,3};
    adj[3] = {1,2};

    cout<<isCycle(n, adj)<<"\n";
    return 0;
}