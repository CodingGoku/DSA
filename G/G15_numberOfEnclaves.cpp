#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &grid, int x, int y, vector<vector<int>> &vis) {
    vis[x][y] = 1;

    queue<pair<int, int>> q;
    q.push({x,y});

    int delRow[] = {0,-1,0,1};
    int delCol[] = {-1,0,1,0};

    while(!q.empty()) {
        int xi = q.front().first;
        int yi = q.front().second;

        q.pop();

        for(int i=0; i<4; i++) {
            int nrow = xi + delRow[i];
            int ncol = yi + delCol[i];

            if(nrow >=0 && nrow < grid.size() && ncol >=0 && ncol < grid[0].size() && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
}

// T : O(n X m)
// S : O(n X m)
int numberOfEnclaves(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m,0));

    //mark 1's connected to the boundary as visited as they cannot be considered
    // top and bottom
    for(int i=0; i<m; i++) {
        if(grid[0][i] == 1 && !vis[0][i]) bfs(grid, 0, i, vis);
        if(grid[n-1][i] == 1 && !vis[n-1][i]) bfs(grid, n-1, i, vis);
    }
    // left and right
    for(int i=0; i<n; i++) {
        if(grid[i][0] == 1 && !vis[i][0]) bfs(grid, i, 0, vis);
        if(grid[i][m-1] == 1 && !vis[i][m-1]) bfs(grid, i, m-1, vis);
    }

    // enclave of 1's that cannot reach boundary
    int enclaves = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 1 && !vis[i][j]) {
                enclaves++;
                bfs(grid, i, j, vis);
            }
        }
    }

    return enclaves;
}

int main()
{
    vector<vector<int>> grid = {{0,0,0,1},
                                {0,1,1,0},
                                {0,1,1,0},
                                {0,0,0,1},
                                {0,1,1,0}};
    
    cout<<"no. of enclaves : "<<numberOfEnclaves(grid);
    return 0;
}