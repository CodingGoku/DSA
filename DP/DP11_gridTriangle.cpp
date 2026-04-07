#include <bits/stdc++.h>
using namespace std;

// fixed start and variable ending

//Recursion
// T: O(2^(1+2+3+....+N))            elenments in each row 1,2,3,...,n and 2 moves at each step d and dr
// S: O(N)          number of rows
int triangle(int i,int j,vector<vector<int>> &grid,int n)
{
    //base case
    if(i==n-1)
    return grid[i][j];

    int d=grid[i][j]+triangle(i+1,j,grid,n); //down
    int dr=grid[i][j]+triangle(i+1,j+1,grid,n); //down and right (right diagonal)

    return min(d,dr);
}

//Memoization
// T: O(N x N)         which is no. of states , not exactly N x N as it is a triangle
// S: O(N)     recursion stack space    + O(N x N)     DP array
int triangleMem(int i,int j,vector<vector<int>> &grid,int n,vector<vector<int>> dp)
{
    //base case
    if(i==n-1)
    return grid[i][j];

    if(dp[i][j]!=-1)
    return dp[i][j];

    int d=grid[i][j]+triangle(i+1,j,grid,n); //down
    int dr=grid[i][j]+triangle(i+1,j+1,grid,n); //down and right (right diagonal)

    dp[i][j]=min(d,dr);
    return dp[i][j];
}

//Tabulation
// T: O(N x N)     which is no. of states , not exactly N x N as it is a triangle
// S: O(N x N)     DP array
int triangleTab(vector<vector<int>>& grid, int n, int m) {
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int j=0; j<n; j++) {
        dp[n-1][j] = grid[n-1][j];
    }

    for(int i=n-2; i>=0; i--) {
        for(int j=i; j>=0; j--) {
            if(i==n-1) dp[i][j] = grid[i][j];

            int d = grid[i][j] + dp[i+1][j];
            int dr = grid[i][j] + dp[i+1][j+1];

            dp[i][j] = min(d,dr);
        }
    }

    return dp[0][0];
}

//Space Optimization
// T: O(N x N)     which is no. of states , not exactly N x N as it is a triangle
// S: O(2N)     front, cur array
int triangleSO(vector<vector<int>>& grid, int n, int m) {
    vector<int> front(n);
    for(int j=0; j<n; j++) {
        front[j] = grid[n-1][j];
    }

    for(int i=n-2; i>=0; i--) {
        vector<int> cur(n);
        for(int j=i; j>=0; j--) {
            if(i==n-1) cur[j] = grid[i][j];

            int d = grid[i][j] + front[j];
            int dr = grid[i][j] + front[j+1];

            cur[j] = min(d,dr);
        }
        front = cur;
    }

    return front[0];
}


int main()
{
    vector<vector<int>> grid{
                                {3,0,0,0,0},
                                {5,7,0,0,0},
                                {8,2,4,0,0},
                                {6,3,7,2,0},
                                {3,7,5,9,1}
                            };
    
    vector<vector<int>> dp(5,vector<int>(5,-1)); //vector of size[5][5] value -1

    cout<<triangle(0,0,grid,5)<<"\n";
    cout<<triangleMem(0,0,grid,5,dp)<<"\n";
    cout<<triangleTab(grid, 5, 5)<<"\n";
    cout<<triangleSO(grid, 5, 5);
    return 0;
}