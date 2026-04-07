#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &grid, int x, int y, vector<vector<int>> &vis) {
    vis[x][y] = 1;

    int delRow[] = {0,-1,0,1};
    int delCol[] = {-1,0,1,0};

    for(int i=0; i<4; i++) {
        int nrow = x + delRow[i];
        int ncol = y + delCol[i];

        if(nrow >=0 && nrow < grid.size() && ncol >=0 && ncol < grid[0].size() && grid[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
            dfs(grid, nrow, ncol, vis);
        }
    }
}


// T : O(n X m)
// S : O(n X m)
vector<vector<char>> replaceOsWithXs(vector<vector<char>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m,0));
    vector<vector<char>> matrix(n, vector<char>(m,0));

    // mark border connected O's as visited as they cannot be converted to X's
    // top and bottom
    for(int i=0; i<m; i++) {
        if(grid[0][i] == 'O' && !vis[0][i]) dfs(grid, 0, i, vis);
        if(grid[n-1][i] == 'O' && !vis[n-1][i]) dfs(grid, n-1, i, vis);
    }
    // left and right
    for(int i=0; i<n; i++) {
        if(grid[i][0] == 'O' && !vis[i][0]) dfs(grid, i, 0, vis);
        if(grid[i][m-1] == 'O' && !vis[i][m-1]) dfs(grid, i, m-1, vis);
    }

    // replace those O's that are not visited to X's
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 'O' && vis[i][j]) matrix[i][j] = 'O';
            else matrix[i][j] = 'X';
        }
    }

    return matrix;
}

int main()
{
    vector<vector<char>> grid = {{'X','X','X','X'},
                                 {'X','O','X','X'},
                                 {'X','O','O','X'},
                                 {'X','O','X','X'},
                                 {'X','X','O','O'}};

    vector<vector<char>> matrix = replaceOsWithXs(grid);
    for(auto i : matrix) {
        for(auto j : i) cout<<j<<" ";
        cout<<"\n";
    }
    return 0;
}