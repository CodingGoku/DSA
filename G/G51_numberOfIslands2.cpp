#include <bits/stdc++.h>
using namespace std;

// class DisjointSet {
// public:
//     vector<vector<int>> size;
//     vector<vector<pair<int, int>>> parent;

//     DisjointSet(int n, int m) {
//         size.resize(n, vector<int>(m));
//         parent.resize(n, vector<pair<int, int>>(m));

//         for(int i=0; i<n; i++) {
//             for(int j=0; j<m; j++) {
//                 parent[i][j] = {i,j};
//                 size[i][j] = 1;
//             }
//         }
//     }

//     pair<int, int> findUPar(int x, int y) {
//         if(parent[x][y].first == x && parent[x][y].second == y) return {x,y};

//         return parent[x][y] = findUPar(parent[x][y].first, parent[x][y].second);
//     }

//     void unionBySize(int x1, int y1, int x2, int y2) {
//         pair<int, int> ulp_1 = findUPar(x1, y1);
//         pair<int, int> ulp_2 = findUPar(x2, y2);

//         if(ulp_1 == ulp_2) return; // there is no need

//         if(size[ulp_1.first][ulp_1.second] > size[ulp_2.first][ulp_2.second]) {
//             parent[ulp_2.first][ulp_2.second] = {ulp_1.first, ulp_1.second};
//             size[ulp_1.first][ulp_1.second] += size[ulp_2.first][ulp_2.second];
//         }
//         else {
//             parent[ulp_1.first][ulp_1.second] = {ulp_2.first, ulp_2.second};
//             size[ulp_2.first][ulp_2.second] += size[ulp_1.first][ulp_1.second];
//         }
//     }
// };

// vector<int> numberOfIslands(int n, int m, vector<vector<int>>& operations) {
//     vector<vector<int>> vis(n,vector<int>(m,0));
//     vector<int> res;
//     int islands = 0;

//     int delrow[] = {0,1,0,-1};
//     int delcol[] = {1,0,-1,0};
//     DisjointSet ds1(n,m);

//     for(auto it : operations) {
//         int x = it[0], y = it[1];

//         if(!vis[x][y]) { // if not visited
//             vis[x][y] = 1; // mark as visited
//             islands++;  // increment islands
//             for(int i=0; i<4; i++) {
//                 int newrow = x+delrow[i];
//                 int newcol = y+delcol[i];

//                 if(newrow>=0 && newrow <n && newcol>=0 && newcol<m && vis[newrow][newcol]) {
//                     if (ds1.findUPar(x,y) != ds1.findUPar(newrow,newcol)) { // not a part of it, need to connect
//                         ds1.unionBySize(x,y,newrow,newcol);
//                         islands--;
//                     }
//                 }
//             }
//         }
//         res.push_back(islands);
//     }
//     return res;
// }

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

// T : n x m x 4 x alpha
// S : n x m
vector<int> numberOfIslands(int n, int m, vector<vector<int>>& operations) {
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<int> res;
    int islands = 0;

    int delrow[] = {0,1,0,-1};
    int delcol[] = {1,0,-1,0};
    DisjointSet ds1(n*m);

    for(auto it : operations) {
        int x = it[0], y = it[1];

        if(!vis[x][y]) { // if not visited
            vis[x][y] = 1; // mark as visited
            islands++;  // increment islands
            for(int i=0; i<4; i++) {
                int newrow = x+delrow[i];
                int newcol = y+delcol[i];

                int node = x*m + y; // row*m + col ... number nodes from 0 to n*m-1
                if(newrow>=0 && newrow <n && newcol>=0 && newcol<m && vis[newrow][newcol]) {
                    int adjNode = newrow*m + newcol;
                    if (ds1.findUPar(node) != ds1.findUPar(adjNode)) { // not a part of it, need to connect
                        ds1.unionBySize(node, adjNode);
                        islands--;
                    }
                }
            }
        }
        res.push_back(islands);
    }
    return res;
}

int main()
{
    vector<vector<int>> operations = {{0,0},{0,0},{1,1},{1,0},{0,1},{0,3},{1,3},{0,4},{3,2},{2,2},{1,2},{0,2}};
    int n = 4, m = 5; // n->rows, m->cols
    vector<int> res = numberOfIslands(n,m, operations);
    cout<<"No. of Islands : ";
    for(auto it : res) cout<<it<<" ";
    return 0;
}