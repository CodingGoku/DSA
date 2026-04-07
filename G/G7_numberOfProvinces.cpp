#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int>& df) {
    vis[node] = 1;
    df.push_back(node);

    for(int i : adj[node]) {
        if(!vis[i]) dfs(i, adj, vis, df);
    }
}

// T : O(V + 2E) ... O(V) for the for loop and DFS visits each node only once O(V+2E)
// S : O(N)
int numberOfProvinces(int V, vector<int> adj[]) {
    vector<int> df;
    int vis[V+1] = {0};

    int provinces=0;
    for(int i=1; i<=V; i++) {
        if(!vis[i]) {
            provinces++;
            dfs(i, adj, vis, df);
        }
    }

    return provinces;
}

int main()
{
    int n = 8;
    vector<int> adj[n+1];
    adj[0] = {};
    adj[1] = {2};
    adj[2] = {1,3};
    adj[3] = {2};
    adj[4] = {5};
    adj[5] = {4,6};
    adj[6] = {5};
    adj[7] = {8};
    adj[8] = {7};

    cout<<numberOfProvinces(n, adj);

    return 0;
}