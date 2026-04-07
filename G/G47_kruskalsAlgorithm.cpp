#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, size;
public:
    // constructor
    DisjointSet(int n) {
        // n+1 if it is 1 based indexing
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++) {
            // initially each node is parent of itself
            parent[i] = i;
            size[i] = 1; // initially each node has size=1
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) return node;
        // assigning to parent before return changes each
        // nodes parent to ultimate parent
        return parent[node] = findUPar(parent[node]);
    }



    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        // they belong to the same component ... no use
        if(ulp_u == ulp_v) return;
        // if size of one's ultimate parent is smaller, then
        // attach to the one with higher size
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else { // when equal or size[ulp_u] > size[ulp_v]
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// T : V + E + Mlog(M) + (M x 4 x alpha x 2)
// S : V + M ... M for edges stored
int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<pair<int, pair<int, int>>> edges;
    // O(V + E)
    for(int i=0; i<V; i++) {
        for(auto it : adj[i]) {
            int node = i;
            int adjNode = it[0];
            int w = it[1];

            edges.push_back({w,{node, adjNode}});
        }
    }

    // sort to get the smallest weight first
    // O(M log(M)) ... if you have M edges
    sort(edges.begin(), edges.end());
    int mstWt = 0;

    // Create disjoint set
    DisjointSet ds1(V);
    // M x 4 x alpha x 2 ... (4 x alpha) for disjoint set and (x2) as findUPar called twice
    for(auto it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds1.findUPar(u) != ds1.findUPar(v)) { // they dont belong to the same component, connect them
            ds1.unionBySize(u,v);
            mstWt+= wt; // add its weight
        }
    }

    return mstWt;
}

int main()
{
    int V = 6;
    vector<vector<int>> adj[V];
    // it is bidirectional so we are adding twice
    adj[0] = {{1,2},{3,1},{4,4}};
    adj[1] = {{0,2},{2,3},{3,3},{5,7}};
    adj[2] = {{1,3},{3,5},{5,8}};
    adj[3] = {{0,1},{1,3},{2,5},{4,9}};
    adj[4] = {{0,4},{3,9}};
    adj[5] = {{1,7},{2,8}};

    cout<<"MST weight : "<<spanningTree(V, adj);
    return 0;
}