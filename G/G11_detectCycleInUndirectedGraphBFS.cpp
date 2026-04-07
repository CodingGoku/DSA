#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int src, vector<int> adj[], int vis[]) {
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1}); // node, parent

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        // traverse adjacent nodes
        for(auto neighbour : adj[node]) {
            if(!vis[neighbour]) {
                vis[neighbour] = 1;
                q.push({neighbour, node});
            }
            else if(neighbour != parent) return true; // if it is already visited and it is not our parent
        }
    }

    return false;
}

// T : O(N + 2E)
// S : O(N) ... for queue and vis   
bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};

    // for connected components
    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            if(detectCycle(i, adj, vis)) return true;
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