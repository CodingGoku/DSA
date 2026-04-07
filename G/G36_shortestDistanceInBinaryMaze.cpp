#include <bits/stdc++.h>
using namespace std;

int shortestDistance(vector<vector<int>>& grid, pair<int, int> source, pair<int, int> destination) {
    // if source is the destination
    if(source.first==destination.first && source.second==destination.second) return 0;
    
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n,vector<int>(m,1e9));
    dist[source.first][source.second] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // priority queue (min heap)
    pq.push({source.first, source.second});

    int delRow[] = {0,1,0,-1};
    int delCol[] = {1,0,-1,0};

    while(!pq.empty()) {
        int x = pq.top().first;
        int y = pq.top().second;
        pq.pop();

        if(x == destination.first && y == destination.second) return dist[destination.first][destination.second];

        // traverse 4 ways, with all weights = 1
        for(int i=0; i<4; i++) {
            int nrow = x + delRow[i];
            int ncol = y + delCol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && dist[x][y] + 1 < dist[nrow][ncol]) {
                dist[nrow][ncol] = dist[x][y] + 1;
                pq.push({nrow, ncol}); // we push it as its dist just got updated, so we need to update its neighbours
            }
        }
    }

    // if cannot reach the destination
    return -1;
}

int main()
{
    vector<vector<int>> grid = {{1,1,1,1},
                                {1,1,0,1},
                                {1,1,1,1},
                                {1,1,0,0},
                                {1,0,0,0}};

    pair<int, int> source = {0,1};
    pair<int, int> destination = {2,2};

    cout<<"shortest distance : "<<shortestDistance(grid, source, destination);
    return 0;
}