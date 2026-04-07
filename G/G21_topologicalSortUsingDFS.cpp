#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& st) {
    vis[node] = 1;

    for(int neighbour : adj[node]) {
        if(!vis[neighbour]) dfs(neighbour, adj, vis, st);
    }

    // when all neighbours of node are visited we push the node into the stack
    st.push(node);
}

// T : O(V + E) ... DFS for directed graph
// S : O(2V)
vector<int> topologicalSort(int V, vector<int> adj[]) {
    vector<int> vis(V,0);
    stack<int> st;

    for(int i=0; i<V; i++) {
        if(!vis[i]) dfs(i, adj, vis, st);
    }

    // now stack has it in topological order
    // topological sort is order poping out of stack
    
    vector<int> res;
    while(!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }

    return res;
}

int main()
{
    int V = 6;
    vector<int> adj[V];
    adj[0] = {};
    adj[1] = {};
    adj[2] = {3};
    adj[3] = {1};
    adj[4] = {0,1};
    adj[5] = {0,2};

    vector<int> res = topologicalSort(V, adj);
    cout<<"topological sort ";
    for(int i : res) cout<<i<<" ";
    return 0;
}