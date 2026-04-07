#include <bits/stdc++.h>
using namespace std;

// T : O(V + E) ... BFS for directed graph
// S : O(V)
void kahnAlgorithm(int V, vector<int> adj[]) {
    int indegree[V] = {0};

    for(int i=1; i<V; i++) {
        for(auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    vector<int> topo;
    // we only push in queue when a node's indegree = 0
    for(int i=1; i<V; i++) {
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

    cout<<"topological sort: ";
    for(int i : topo) cout<<i<<" ";
    // if topological sort has all the Vertices
    if(topo.size() == V-1) cout<<"\n It is Acyclic";
    else cout<<"\n It is Cyclic";
}

int main()
{
    int V = 6;
    vector<int> adj[V];
    adj[0] = {};
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {4,5};
    adj[4] = {2};
    adj[5] = {};

    kahnAlgorithm(V, adj);
    
    return 0;
}