#include <bits/stdc++.h>
using namespace std;

// Recursion
// T : exponential
int mcm(int i, int j, vector<int> arr)
{
    if(i == j) return 0;
    int mini = 1e9;
    for(int k=i; k<j; k++)
    {
        int steps = arr[i-1]*arr[k]*arr[j] + mcm(i, k, arr)
            + mcm(k+1, j, arr);
        if(steps < mini) mini = steps;
    }
    return mini;
}

// Memoization
// T : O(N x N) x N   ... O(n^3)
// S : O(N^2) + O(N) auxiliary stack space
int mcmMem(int i, int j, vector<int> arr, vector<vector<int>> dp)
{
    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini = 1e9;
    for(int k=i; k<j; k++)
    {
        int steps = arr[i-1]*arr[k]*arr[j] + mcm(i, k, arr)
            + mcm(k+1, j, arr);
        if(steps < mini) mini = steps;
    }
    return dp[i][j] = mini;
}

// Tabulation
int mcmTab(vector<int> arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n,0));

    for(int i = n-1; i>=1; i--)
    {
        for(int j = i+1; j<n; j++)
        {
            int mini = 1e9;
            for(int k=i; k<j; k++)
            {
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k]
                    + dp[k+1][j];
                if(steps < mini) mini = steps;
            }
            dp[i][j] = mini;
                }
    }
    return dp[1][n-1];
}

int main()
{
    vector<int> arr {10,20,30,40,50};
    int n = arr.size();
    cout<<"recursion : "<<mcm(1, n-1, arr)<<"\n";

    //dp[n][n]
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<"memoization : "<<mcmMem(1, n-1, arr, dp)<<"\n";

    cout<<"tabulation : "<<mcmTab(arr)<<"\n";
    return 0;
}