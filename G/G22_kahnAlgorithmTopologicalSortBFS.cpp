#include <bits/stdc++.h>
using namespace std;

// T : O(V + E) ... BFS for directed graph
// S : O(V)
vector<int> kahnAlgorithm(int V, vector<int> adj[]) {
    int indegree[V] = {0};

    for(int i=0; i<V; i++) {
        for(auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    vector<int> topo;
    // we only push in queue when a node's indegree = 0
    for(int i=0; i<V; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        // this node is in topological sort, so remove indegree coming from this node
        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }

    return topo;
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

    vector<int> res = kahnAlgorithm(V, adj);
    cout<<"topological sort: ";
    for(int i : res) cout<<i<<" ";
    return 0;
    return 0;
}