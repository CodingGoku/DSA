#include <bits/stdc++.h>
using namespace std;

// T : O(n X m)
// S : O(n X m)
vector<vector<int>> nearest(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;

    // inserting all 1's
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 1) {
                q.push({{i,j},0}); // (x, y, dist) ... dist of 1 to nearest 1 is 0
                vis[i][j] = 1;
            }
        }
    }

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;

        q.pop();

        dist[x][y] = d; // mark the distance

        int delRow[] = {0,-1,0,1};
        int delCol[] = {-1,0,1,0};
        // visit neighbours
        for(int i=0; i<4; i++) {
            int nrow = x + delRow[i];
            int ncol = y + delCol[i];
            if(nrow >=0 && nrow < n && ncol >=0 && ncol < n && !vis[nrow][ncol]) {
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, d+1});
            }
        }
    }

    return dist;
}

int main()
{
    vector<vector<int>> grid = {{0,0,0},
                                {0,1,0},
                                {1,0,1}};

    vector<vector<int>> dist = nearest(grid);
    for(auto i : dist) {
        for(auto j : i) cout<<j<<" ";
        cout<<"\n";
    }
    return 0;
}