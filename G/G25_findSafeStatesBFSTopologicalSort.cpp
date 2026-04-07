#include <bits/stdc++.h>
using namespace std;

// T : O(V + E + VLogV) ... BFS for directed graph
// S : O(4V)
vector<int> safeStates(int V, vector<int> adj[]) {
    // reverse the direction of edges
    vector<int> revAdj[V];
    int indegree[V] = {0};

    for(int i=0; i<V; i++) {
        for(int neighbour : adj[i]) { // earlier i -> neighbour
            revAdj[neighbour].push_back(i); // neighbour -> i
            indegree[i]++;
        }
    }

    // topological sort using BFS Kahn's Algorithm
    queue<int> q;
    for(int i=0; i<V; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();

        topo.push_back(node);
        // at node added to topo, remove all its edges to other nodes
        for(int neighbour : revAdj[node]) {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0) q.push(neighbour);
        }
    }

    // now topo will only have safe states
    sort(topo.begin(), topo.end());
    return topo;
}

int main()
{
    int V = 12;
    vector<int> adj[V];
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {4,5};
    adj[4] = {6};
    adj[5] = {6};
    adj[6] = {7};
    adj[7] = {};
    adj[8] = {9};
    adj[9] = {10};
    adj[10] = {8};
    adj[11] = {9};

    vector<int> safe = safeStates(V, adj);
    cout<<"Safe States: ";
    for(int i : safe) cout<<i<<" ";
    return 0;
}