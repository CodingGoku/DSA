#include <bits/stdc++.h>
using namespace std;

// T : E log V ... same as Dijkstra ... E = n x m x 4 for 4 directions, V = n x m
// S : V ... V = n x m
int pathWithMinimumEffort(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    pair<int, int> target = {n-1,m-1}; // bottom right corner

    priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> pq; // min heap pq
    pq.push({0,{0,0}}); // maxDifference, x, y ... max diff is the max diff throughout the path till x,y

    vector<vector<int>> diff(n,vector<int>(m,1e9)); // initially difference on each node is infinity
    diff[0][0] = 0; // starting node shoud have diff = 0

    int delrow[] = {0,1,0,-1};
    int delcol[] = {1,0,-1,0};

    while(!pq.empty()) {
        int maxDiff = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        for(int i=0; i<4; i++) {
            int nrow = x + delrow[i];
            int ncol = y + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m) {
                // don't update maxDiff itself as it will get changed for next iteration and will give wrong answer
                int newEffort = max(maxDiff,abs(grid[x][y]-grid[nrow][ncol]));
                if(diff[nrow][ncol] > newEffort) {
                    diff[nrow][ncol] = newEffort;
                    pq.push({newEffort, {nrow, ncol}});
                }
            }
        }
    }

    return diff[target.first][target.second];
}

int main()
{
    vector<vector<int>> grid {{1,2,2},
                              {3,8,2},
                              {5,3,5}};
    cout<<"maxDiff: "<<pathWithMinimumEffort(grid);
    return 0;
}