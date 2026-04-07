#include <bits/stdc++.h>
using namespace std;

//Recursion
int MinPathSum(vector<vector<int>> &grid,int i,int j)
{
    //base case
    if(i==0 && j==0)
    return grid[i][j];

    if(i<0 || j<0)
    return 1e9; // we got outside of the 2D vector ... so we set it to max as we want min
                // NOTE: I took INT_MAX first instead of 1e9 but it was giving me a very large negative value
                // as it was rolling back the other side after adding back to the INT_MAX

    int left=grid[i][j]+MinPathSum(grid,i,j-1);
    int up=grid[i][j]+MinPathSum(grid,i-1,j);
    return min(left,up);
}

//Memoization
// T: O(N x M)   at max N x M calls for fun() as it is N x M matrix
// S: O((n-1)+(m-1)    path lenght     +    O(N x M)     for DP array)
int MinPathSumMem(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp)
{
    //base case
    if(i==0 && j==0)
    return grid[i][j];

    if(i<0 || j<0)
    return 1e9; // we got outside of the 2D vector ... so we set it to max as we want min

    if(dp[i][j]!=-1)
    return dp[i][j];

    int left=grid[i][j]+MinPathSumMem(grid,i,j-1,dp);
    int up=grid[i][j]+MinPathSumMem(grid,i-1,j,dp);

    dp[i][j]=min(left,up);
    return dp[i][j];
}

//Tabulation
int MinPathSumTab(vector<vector<int>> &grid, int m, int n)
{
    vector<vector<int>> dp(m,vector<int>(n)); // dp[m][n]

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 && j==0) dp[i][j]=grid[0][0];
            else
            {
                int left,up;
                // NOTE: don't take together (j>0 && i>0) it will give wrong answer
                if(j>0) left=grid[i][j]+dp[i][j-1];  // (j>0) as when j=0 it will be negative (-ve)
                else{left=1e9;}
                if(i>0) up=grid[i][j]+dp[i-1][j];  //// (i>0) as when j=0 it will be negative (-ve)
                else{up=1e9;}
                
                dp[i][j]=min(left,up);
            }
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    vector<vector<int>> grid {
                                {2,5,3,7},
                                {7,4,9,1},
                                {5,2,3,9},
                                {8,5,7,4}
                            };
    int m=4; //rows
    int n=4; //columns

    vector<vector<int>> dp(4,vector<int>(4,-1));

    cout<<MinPathSum(grid,m-1,n-1)<<"\n";
    cout<<MinPathSumMem(grid,m-1,n-1,dp)<<"\n";
    cout<<MinPathSumTab(grid,m,n)<<"\n";
    return 0;
}