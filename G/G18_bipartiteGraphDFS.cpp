#include <bits/stdc++.h>
using namespace std;

bool bipartiteComponent(int node, int col, vector<int> adj[], vector<int> &colour) {
    colour[node] = col;

    for(int neighbour : adj[node]) {
        if(colour[neighbour] == -1) {
            if(!bipartiteComponent(neighbour, !col, adj, colour)) return false;
        }
        else if(colour[neighbour] == colour[node]) return false;
    }
    return true;
}

// O(V + 2E) ... same as DFS
// O(V)
bool isBipartiteGraph(int V, vector<int> adj[]) {
    vector<int> colour(V+1,-1);

    for(int i=1; i<=V; i++) {
        if(colour[i] == -1) {
            if(!bipartiteComponent(i, 0, adj, colour)) return false;
        }
    }
    return true;
}

int main()
{
    int n = 6;
    vector<int> adj[n+1];
    adj[0] = {};
    adj[1] = {2};
    adj[2] = {1,3,5};
    adj[3] = {2,4};
    adj[4] = {3,5,6};
    adj[5] = {2,4};
    adj[6] = {4};

    cout<<"isBipartite : "<<isBipartiteGraph(n, adj);
    return 0;
}