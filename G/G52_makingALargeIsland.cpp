#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> size, parent;
    
    DisjointSet(int n) {
        size.resize(n*n);
        parent.resize(n*n);
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

        if(ulp_u == ulp_v) return; // this is no use

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

// T : n x n
// S : n x n
int largeIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    DisjointSet ds1(n*n);

    int delrow[] = {0,1,0,-1};
    int delcol[] = {1,0,-1,0};

    // find size of current islands
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] == 1) { // connect to neighbours
                int node = i*n+j; // row*m + col ... for node number
                // neighbours
                for(int k=0; k<4; k++) {
                    int newrow = i+delrow[k];
                    int newcol = j+delcol[k];

                    if(newrow>=0 && newrow<n && newcol>=0 && newcol<n && grid[newrow][newcol]==1) {
                        int adjNode = newrow*n + newcol;
                        ds1.unionBySize(node, adjNode);
                    }
                }
            }
        }
    }

    int largestIslandSize = 0;
    // find largest island if you convert only 1 node from 0 to 1
    // and checking the size of neighbouring islands
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] == 0) {
                int node = i*n+j; // row*m + col ... for node number
                set<int> st;
                // neighbours
                for(int k=0; k<4; k++) {
                    int newrow = i + delrow[k];
                    int newcol = j + delcol[k];

                    if(newrow>=0 && newrow<n && newcol>=0 && newcol<n && grid[newrow][newcol]==1) {
                        int adjNode = newrow*n + newcol; // row*m + col ... for node number
                        st.insert(ds1.parent[adjNode]); // set will ensure that if this island is also occuring in
                                                      // any other direction, we won't insert it twice
                    }
                }

                int currIslandSize = 0;
                for(auto it : st) currIslandSize += ds1.size[it];

                largestIslandSize = max(largestIslandSize, currIslandSize+1); // +1 for 1 node that we can insert
            }
        }
    }

    return largestIslandSize;
}

int main()
{
    vector<vector<int>> grid = {{1,1,0,1,1},
                                {1,1,0,1,1},
                                {1,1,0,1,1},
                                {0,0,1,0,0},
                                {0,0,1,1,1},
                                {0,0,1,1,1}};
    cout<<"lasrgest island size : "<<largeIsland(grid);
    return 0;
}