#include <bits/stdc++.h>
using namespace std;

// T : 3(V+E) ... step 1,2,3
// S : 2V ... vis and stack
void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st) {
    vis[node] = 1;

    for(auto it : adj[node]) {
        if(!vis[it]) dfs(it, vis, adj, st);
    }

    st.push(node);
}

// used when poping from stack ... so no need for stack
void dfs2(int node, vector<int>& vis, vector<int> adjT[], vector<vector<int>>& scc, int si) {
    vis[node] = 1;
    scc[si].push_back(node);

    for(auto it : adjT[node]) {
        if(!vis[it]) dfs2(it, vis, adjT, scc, si);
    }
}

int kosaraju(int V, vector<int> adj[]) {
    vector<int> vis(V,0);
    // step 1 : sort the nodes according to finishing time of traversal
    stack<int> st;
    // O(V+E)
    for(int i=0; i<V; i++) {
        if(!vis[i]) dfs(i, vis, adj, st);
    }

    // step 2 : reverse all the edges
    vector<int> adjT[V];
    // O(V+E)
    for(int i=0; i<V; i++) {
        for(auto it : adj[i]) {
            // originally : i -> it
            // reverse : it -> i
            adjT[it].push_back(i);
        }
    }

    // step 3 : dfs traverse in order given in stack
    vector<vector<int>> scc;
    int si=0;

    fill(vis.begin(), vis.end(), 0);

    // O(V+E)
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(!vis[node]) {
            scc.push_back(vector<int>());
            dfs2(node, vis, adjT, scc, si);
            si++; // new component at it is not visited
        }
    }

    // print scc
    for(auto i : scc) {
        for(auto j : i) cout<<j<<" ";
        cout<<"\n";
    }

    return si;
}

int main()
{
    int V = 8;
    vector<int> adj[V];
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {0,3};
    adj[3] = {4};
    adj[4] = {5,7};
    adj[5] = {6};
    adj[6] = {4,7};
    adj[7] = {};
    cout<<kosaraju(V, adj) <<" strongly connected components";
    return 0;
}