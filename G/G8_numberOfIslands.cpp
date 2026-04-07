#include <bits/stdc++.h>
using namespace std;

void bfs(int i, int j, vector<vector<int>>& islands, vector<vector<int>>& vis) {
    int n = islands.size();
    int m = islands[0].size();

    vis[i][j] = 1;
    queue<pair<int,int>> q;
    q.push({i,j});

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // traverse all neighbours
        for(int delRow=-1; delRow<=1; delRow++) {
            for(int delCol=-1; delCol<=1; delCol++) {
                int nrow = row+delRow;
                int ncol = col+delCol;

                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m 
                && islands[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}

// T : (NxMx9)
// S : (NxM) ... vis
int numberOfIslands(vector<vector<int>>& islands) {
    int n = islands.size();
    int m = islands[0].size();

    vector<vector<int>> vis(n, vector<int>(m,0));

    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(islands[i][j] == 1 && !vis[i][j]) {
                cnt++;
                bfs(i, j, islands, vis);
            }
        }
    }

    return cnt;
}

int main()
{
    vector<vector<int>> islands = {{0,1,1,0},
                                   {0,1,1,0},
                                   {0,0,1,0},
                                   {0,0,0,0},
                                   {1,1,0,1}};

    cout<<numberOfIslands(islands);
    return 0;
}