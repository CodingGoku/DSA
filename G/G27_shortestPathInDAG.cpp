#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<pair<int, int>> adj[], int vis[], stack<int>& st) {
    vis[node] = 1;

    for(auto i : adj[node]) { // u(node) -> v,w 
        int v = i.first;
        if(!vis[v]) topoSort(v, adj, vis, st);
    }

    // push to stack after all the neighbours of node are visited
    st.push(node);
}

// T : O(V + E) ... topo sort + O(N + M)
vector<int> shortestPath(int N, int M, vector<int> edges[], int startNode) { // N -> vertices, M -> edges
    vector<pair<int, int>> adj[N];
    for(int i=0; i<M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v,wt});
    }

    stack<int> st;
    int vis[N] = {0};
    // for connected componets
    for(int i=0; i<N; i++) {
        if(!vis[i]) topoSort(i, adj, vis, st);
    }

    vector<int> dist(N,1e9);
    dist[startNode] = 0; // starting node has distance 0

    // O(N + M) ... N for while loop, M for for loop
    while(!st.empty()) {
        int node = st.top();
        st.pop();

        for(auto it : adj[node]) {
            int v = it.first;
            int wt = it.second;

            if(dist[node] + wt < dist[v]) {
                dist[v] = dist[node] + wt;
            }
        }
    }

    // if not able to reach a node from the given src
    for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
    }

    return dist;
}

int main()
{
    int N = 6;
    int M = 7;
    vector<int> edges[M] = {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
    vector<int> dist = shortestPath(N, M, edges, 0);
    for(int i : dist) cout<<i<<" ";

    N = 7;
    M = 8;
    vector<int> edges2[M] = {{0,1,2},{1,3,1},{2,3,3},{4,0,3},{4,2,1},{5,4,1},{6,4,2},{6,5,3}};
    dist = shortestPath(N, M, edges2, 6);
    cout<<"\n\n";
    for(int i : dist) cout<<i<<" ";
    return 0;
}