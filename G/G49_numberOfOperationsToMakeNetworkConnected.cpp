#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1);

        for(int i=0; i<n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if(parent[node] == node) return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return; // there is no use

        if(size[ulp_v] > size[ulp_u]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// T : m x 4 x alpha + n
// S : n    
int noOfOperationsToConnect(int n, int m, vector<vector<int>>& edges) { // n -> vertices, m -> edges
    int extraEdges = 0;

    DisjointSet ds1(n);
    for(auto it : edges) {
        int u = it[0];
        int v = it[1];

        if(ds1.findUPar(u) == ds1.findUPar(v)) { // belong to the same component, no need for this edge
            extraEdges++;
        }
        else { // don't belong to the same component connect them
            ds1.unionBySize(u,v);
        }
    }

    int components = 0;
    // now check for no. of connected componenets that needs to be connected
    for(int i=0; i<n; i++) {
        if(ds1.parent[i] == i) components++; // if a node is parent of itself, it can happen only once in each component
    }
    cout<<"\n\nextra edges : "<<extraEdges<<endl;
    int edgesRequired = components-1; // components-1 edges to connect them

    if(edgesRequired > extraEdges) return -1; // not possible

    cout<<"Number of Operations : ";
    return edgesRequired;
}

int main()
{
    int n = 4;
    int m = 3;
    vector<vector<int>> edges = {{0,1},{0,2},{1,2}};
    cout<<noOfOperationsToConnect(n,m,edges);

    n = 9;
    m = 8;
    vector<vector<int>> edges2 = {{0,1},{1,2},{2,3},{3,0},{2,0},{4,5},{5,6},{7,8}};
    cout<<noOfOperationsToConnect(n,m,edges2);
    return 0;
}