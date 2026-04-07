#include <bits/stdc++.h>
using namespace std;

// T : O(NxM + NxMx4)
// S : O(NxM)
int rottenOranges(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m,0));

    // we apply BFS as it is level order and we need the minimum time to rot
    queue<pair<pair<int, int>, int>> q; // q(row, col, time)
    // push the rotten oranges in the queue with the index and time
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 2) {
                vis[i][j] = 2;
                q.push({{i,j},0}); //initially time is 0
            }
        }
    }

    int tm = 0;
    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        tm = max(tm, t); // to get max total time to rot

        int delRow[] = {0,-1,0,1};
        int delCol[] = {-1,0,1,0};
        // check the neighbours
        for(int i=0; i<4; i++) {
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2) {
                vis[nrow][ncol] = 2; // rot it
                q.push({{nrow, ncol}, t+1}); // increment the time
            }
        }
    }

    // check if any fresh orange is left
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 1 && vis[i][j] != 2) {
                return -1;
            }
        }
    }

    return tm;
}

int main()
{
    vector<vector<int>> grid = {{0,1,2},
                                {0,1,1},
                                {2,1,1}};

    cout<<rottenOranges(grid);
    return 0;
}