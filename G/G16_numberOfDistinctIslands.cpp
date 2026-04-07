#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, int x, int y, vector<vector<int>> &vis, vector<pair<int, int>> &shapeCorr, int startX, int startY) {
    vis[x][y] = 1;
    // set the points to a reference point {0,0} by subtracting first point from each point
    shapeCorr.push_back({x-startX,y-startY}); // coordinates of this point with 1

    int delRow[] = {0,-1,0,1};
    int delCol[] = {-1,0,1,0};

    for(int i=0; i<4; i++) {
        int nRow = x + delRow[i];
        int nCol = y + delCol[i];

        if(nRow >= 0 && nRow < grid.size() && nCol >= 0 && nCol < grid[0].size() && grid[nRow][nCol] == 1 && !vis[nRow][nCol]) {
            dfs(grid, nRow, nCol, vis, shapeCorr, startX, startY);
        }
    }
}

// T : n X m X log(n X m) + (n X m X 4) ... for loop, set insertion, dfs
// S : n X m
int numberOfDistinctIslands(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m,0));
    set<vector<pair<int, int>>> s; // to store the distinct shapes

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 1 && !vis[i][j]) {
                vector<pair<int, int>> shapeCorr;
                dfs(grid, i, j, vis, shapeCorr, i, j);

                s.insert(shapeCorr);
            }
            
        }
    }

    for(auto i : s) 
        {
            for(auto j : i) cout<<"("<<j.first<<", "<<j.second<<") ";
            cout<<endl;
            }

    return s.size();
}

int main()
{
    vector<vector<int>> grid = {{1,1,0,1,1},
                                {1,0,0,0,0},
                                {0,0,0,1,1},
                                {1,1,0,1,0}};

    cout<<numberOfDistinctIslands(grid)<<" Distinct Islands";
    return 0;
}