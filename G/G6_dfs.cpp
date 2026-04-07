#include <bits/stdc++.h>
using namespace std;

// T : O(N + 2E) ... N for traversing each node, and the for loop checks the adj for each node
//                   which is the degree at each node, so the total degree is 2E
// S : O(3N) ... N for each of vis, df, recursion stack space in case of skew graph
void dfs(int node, vector<int> adj[], int vis[], vector<int>& df) {
    vis[node] = 1;
    df.push_back(node);

    //traverse all its neighbours
    for(int i : adj[node]) {
        if(!vis[i]) dfs(i, adj, vis, df);
    }
}

int main()
{
    int n = 9; // vertex
    vector<int> adj[n+1]; // vector in each array element

    // if start with node 0
    adj[0].push_back(1);
    adj[1].push_back(0);

    // total 2 x E = 2 x 9 = 18
    adj[1].push_back(2);
    adj[1].push_back(6);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(2);
    adj[4].push_back(2);
    adj[4].push_back(5);
    adj[5].push_back(4);
    adj[5].push_back(8);
    adj[6].push_back(1);
    adj[6].push_back(7);
    adj[6].push_back(9);
    adj[7].push_back(6);
    adj[7].push_back(8);
    adj[8].push_back(5);
    adj[8].push_back(7);
    adj[9].push_back(6);

    int vis[n+1] = {0};
    vector<int> df;
    int start = 0;
    dfs(start, adj, vis, df);

    for(int i : df) cout<<i<<" ";
    return 0;
}