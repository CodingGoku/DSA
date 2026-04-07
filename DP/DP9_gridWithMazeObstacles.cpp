#include <bits/stdc++.h>
using namespace std;

//recursion
int gridWithObstacles(vector<vector<int>> grid, int i,int j)
{
    if(i==0 && j==0)
    return 1;

    if(i<0 || j<0)
    return 0;

    if(grid[i][j]!=-1) // if no obstacle then move left or up
    {
        int left=gridWithObstacles(grid,i,j-1);
        int up=gridWithObstacles(grid,i-1,j);
        return left+up;
    }

    return 0; // else (if obstacle) return 0 .... path rejected
}

//Memoization
int gridWithObstaclesMem(vector<vector<int>> grid, int i,int j,vector<vector<int>> dp)
{
    if(i==0 && j==0)
    return 1;

    if(i<0 || j<0)
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    if(grid[i][j]!=-1) // if no obstacle then move left or up
    {
        int left=gridWithObstaclesMem(grid,i,j-1,dp);
        int up=gridWithObstaclesMem(grid,i-1,j,dp);

        dp[i][j]=left+up;
        return dp[i][j];
    }

    return 0; // else (if obstacle) return 0 .... path rejected
}

//Tabulation
int gridWithObstaclesTab(vector<vector<int>> grid, int n,int m,vector<vector<int>> dp)
{
    vector<vector<int>> dp(n, vector<int>(m, 0)); // Initialize a DP table to store minimum path sums

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
            else {
                // Calculate the minimum path sum considering moving up and moving left
                int up = grid[i][j];
                if (i > 0)
                    up += dp[i - 1][j]; // Include the minimum path sum from above
                else
                    up += 1e9; // A large value if moving up is not possible (out of bounds)

                int left = grid[i][j];
                if (j > 0)
                    left += dp[i][j - 1]; // Include the minimum path sum from the left
                else
                    left += 1e9; // A large value if moving left is not possible (out of bounds)

                // Store the minimum path sum in dp[i][j]
                dp[i][j] = min(up, left);
            }
        }
    }
}

int main()
{
    vector<vector<int>> grid {
                                {0,0,-1,0},
                                {-1,0,0,0},
                                {0,0,0,0},
                                {0,-1,0,0}
                            };

    int m=4; //rows
    int n=4; //columns
    cout<<gridWithObstacles(grid,m-1,n-1)<<"\n";

    vector<vector<int>> dp(m,vector<int>(n,-1)); // dp[m][n] value = -1
    cout<<gridWithObstaclesMem(grid,m-1,n-1,dp);
    return 0;
}