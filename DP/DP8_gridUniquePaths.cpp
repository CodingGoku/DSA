#include <bits/stdc++.h>
using namespace std;

//recursion
// T: 2^(mXn)   exponential
// S: (m-1)+(n-1)    path lenght (recursion stack space)
int allPaths(int i,int j)
{
    //base case
    if(i==0 && j==0)
    return 1;

    if(i<0 || j<0)
    return 0;

    int left=allPaths(i,j-1);
    int up=allPaths(i-1,j);
    return left+up;
}

//Memoization
// T: O(N x M)   at max N x M calls for fun() as it is N x M matrix
// S: O((n-1)+(m-1)    path lenght     +    O(N x M)     for DP array)
int allPathsMem(int i,int j,vector<vector<int>> dp)
{
    //base case
    if(i==0 && j==0)
    return 1;

    if(i<0 || j<0)
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    int left=allPathsMem(i,j-1,dp);
    int up=allPathsMem(i-1,j,dp);

    dp[i][j]=left+up;
    return dp[i][j];
}

// Memoization ----> Tabulation
// 1. Declare Base case
// 2. Express all states in for loop
// 3. Copy the recurrence and write

//Tabulation
// T: O(N x M) nested for loops
// S: O(N x M) for space used, no recursion stack space
int allPathsTab(int m,int n)
{

    vector<vector<int>> dp(m,vector<int> (n,0));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 && j==0) dp[i][j]==1;
            else
            {
                int left=0;
                int up=0;
                if(j>0) left=dp[i][j-1];
                if(i>0) up=dp[i-1][j];
                dp[i][j]=left+up;
            }
        }
    }
    return dp[m-1][n-1];
}

// If there is a previous row and previous column we can SPACE OPTIMIZE it.

//Space Optimization
// T: O(N x M) nested for loops
// S: O(N) for 1D array of size N
int allPathsSO(int m,int n) // m -> rows  ,  n-> columns
{

    vector<vector<int>> dp(m,vector<int> (n,0));
    vector<int> prev (n,0);    // a single row with n elements (for previous row)
    for(int i=0;i<m;i++)
    {
        vector<int> curr (n,0);         // a single row with n elements (for current row)
        for(int j=0;j<n;j++)
        {
            
            if(i==0 && j==0) dp[i][j]==1;   // dp[i] --> curr    (dp[i] means current row)
            else
            {

                //dp[i][j]  = dp[i-1][j] + dp[i][j-1];    (up + left)
                curr[j] = prev[j] + curr[j-1];
                
            }
        }
        prev=curr;
    }
    return prev[n-1];
}

using namespace std;
int main()
{
    int m=3,n=3;
    cout<<allPaths(m-1,n-1)<<"\n";

    vector<vector<int>> dp(m,vector<int>(n,-1)); //vector dp[m][n] value -1
    cout<<allPathsMem(m-1,n-1,dp)<<"\n";
    cout<<allPathsTab(m,n)<<"\n";
    cout<<allPathsSO(m,n);
    return 0;
}