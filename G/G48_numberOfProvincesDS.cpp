#include <bits/stdc++.h>
using namespace std;

class DisjointSet {

public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1);

        for(int i=0; i<=n; i++) {
            parent[i] = i; // initially node is parent of itself
            size[i] = 1; // initially each node is independent
        }
    }

    int findUPar(int node) {
        if(parent[node] == node) return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return; // both belong to same component ... no use

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// T : (V x V) + V ... traversing adjMatrix
// S : V
int numberOfProvinces(int V, vector<vector<int>> adj) {
    DisjointSet ds1(V);
    // given an adjacency matrix
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            if(adj[i][j] == 1) ds1.unionBySize(i,j);
        }
    }

    int cnt=0;
    for(int i=0; i<V; i++) {
        // in each component there is only one node which is ultimate parent of itself
        if(ds1.parent[i] == i) cnt++; // parent stores the ultimate parent
    }

    return cnt;
}

int main()
{
    vector<vector<int>> adjMatrix = {{0,1,0,0,0,0,0},
                                     {1,0,1,0,0,0,0},
                                     {0,1,0,0,0,0,0},
                                     {0,0,0,0,1,0,0},
                                     {0,0,0,1,0,0,0},
                                     {0,0,0,0,0,0,1},
                                     {0,0,0,0,0,1,0}};
    int V = 7;
    cout<<"No. of provinces : "<<numberOfProvinces(V, adjMatrix);
    return 0;
}