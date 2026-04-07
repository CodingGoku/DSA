#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> size, parent;

    DisjointSet(int n) {
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) {
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

int mostStonesRemoved(vector<vector<int>>& stones) {
    int n = stones.size();
    int m = stones[0].size();

    DisjointSet ds1(n*m);

    // connect stones with stones on same row and col
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(stones[i][j] == 1) { // try connecting with its row & col stones
                int node = i*m + j; // row*m + col ... node number

                // connect with row stones
                for(int k=0; k<m; k++) {
                    if(stones[i][k] == 1 && k!=j) { // except current stone
                        int adjNode = i*m + k; // row*m + col ... node number
                        ds1.unionBySize(node, adjNode); // connect with this node on same row
                    }
                }

                // connect with col stones
                for(int k=0; k<n; k++) {
                    if(stones[k][j] == 1 && k!=i) { // except current stone
                        int adjNode = k*m + j; // row*m + col ... node number
                        ds1.unionBySize(node, adjNode); // connect with this node on same col
                    }
                }
            }
        }
    }

    // find number of components
    int c = 0;
    int totalStones = 0;
    for(int i=0; i<n*m; i++) {
        if(ds1.parent[i] == i) { // if it is ultimate parent
            c++;
            totalStones += ds1.size[i]; // adding stones from each component
        }
    }

    int stonesRemoved = totalStones - c; // from each component 1 stone will be left out
    return stonesRemoved;
}

int main()
{
    vector<vector<int>> stones = {{1,0,1,0},
                                  {0,0,0,1},
                                  {0,1,1,0},
                                  {0,0,0,1}};
    cout<<"stones removed : "<<mostStonesRemoved(stones);
    return 0;
}