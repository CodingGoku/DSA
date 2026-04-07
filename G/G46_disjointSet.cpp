#include <bits/stdc++.h>
using namespace std;

// T : 4(alpha) = O(1)
// S : V
class DisjointSet {
    vector<int> rank, parent, size;
public:
    // constructor
    DisjointSet(int n) {
        // n+1 if it is 1 based indexing
        rank.resize(n+1,0);
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

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        // they belong to the same component ... no use
        if(ulp_u == ulp_v) return;
        // if rank of one's ultimate parent is smaller, then
        // attach to the one with higher rank
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else { // if both ulp-rank same attach to anyone
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
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

int main()
{
    // Union By Rank
    DisjointSet ds1(7);
    ds1.unionByRank(1,2);
    ds1.unionByRank(2,3);
    ds1.unionByRank(4,5);
    ds1.unionByRank(6,7);
    ds1.unionByRank(5,6);

    // if 3 and 7 are in same component or not
    if(ds1.findUPar(3) == ds1.findUPar(7)) cout<<"Same\n";
    else cout<<"Not Same\n";

    ds1.unionByRank(3,7); // join the components

    if(ds1.findUPar(3) == ds1.findUPar(7)) cout<<"Same\n";
    else cout<<"Not Same\n";

    cout<<"\n";

    // Union By Size
    DisjointSet ds2(7);
    ds2.unionByRank(1,2);
    ds2.unionByRank(2,3);
    ds2.unionByRank(4,5);
    ds2.unionByRank(6,7);
    ds2.unionByRank(5,6);

    // if 3 and 7 are in same component or not
    if(ds2.findUPar(3) == ds2.findUPar(7)) cout<<"Same\n";
    else cout<<"Not Same\n";

    ds2.unionByRank(3,7); // join the components

    if(ds2.findUPar(3) == ds2.findUPar(7)) cout<<"Same\n";
    else cout<<"Not Same\n";
    return 0;
}