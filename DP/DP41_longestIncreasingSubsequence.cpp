#include <bits/stdc++.h>
using namespace std;

// Recursion
// T : O(2^N)   .... take, not_take
// S : O(N) ...  recursion stack space
int LIS(vector<int> arr, int ind, int prev_ind)
{
    //base case
    if(ind==arr.size()) return 0;

    int not_take = 0 + LIS(arr, ind+1, prev_ind);
    int take = 0;
    if(prev_ind==-1 || arr[ind]>arr[prev_ind]) take = 1 + LIS(arr, ind+1, ind);
    return max(take, not_take);
}

// Memoization
int LISMem(vector<int> arr, int ind, int prev_ind, vector<vector<int>> dp)
{
    //base case
    if(ind==arr.size()) return 0;

    if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1]; // prev_ind -> prev_ind+1 shift as in dp array -1 inidex is not possible

    int not_take = 0 + LIS(arr, ind+1, prev_ind);
    int take = 0;
    if(prev_ind==-1 || arr[ind]>arr[prev_ind]) take = 1 + LIS(arr, ind+1, ind);
    return dp[ind][prev_ind+1] = max(take, not_take); // dp[0][-1] not possible so shifted prev_ind
}

// Tabulation
int LISTab(vector<int> arr)
{
    int n = arr.size();
    vector<vector<int>> dp (n+1, vector<int> (n+1,0)); // index n+1 : 0 -> n , as base case ind == n return 0;

    for(int ind = n-1; ind>=0; ind--)
    {
        for(int prev_ind = ind-1; prev_ind>=-1; prev_ind--) // as prev_ind is always 1 less than current ind so, prev_ind = ind-1
        {
            int not_take = 0 + dp[ind+1][prev_ind+1];
            int take = 0;
            if(prev_ind==-1 || arr[ind]>arr[prev_ind]) take = 1 + dp[ind+1][ind+1]; // every 2nd parameter +1 , as coordinate shift for prev_ind
            dp[ind][prev_ind+1] = max(take, not_take);
        }
    }
    return dp[0][-1+1];
}

// Space Optimization
int LISSO(vector<int> arr)
{
    int n = arr.size();
    vector<int> next (n+1,0), curr (n+1,0);

    for(int ind = n-1; ind>=0; ind--)
    {
        for(int prev_ind = ind-1; prev_ind>=-1; prev_ind--)
        {
            int not_take = 0 + next[prev_ind+1];
            int take = 0;
            if(prev_ind==-1 || arr[ind]>arr[prev_ind]) take = 1 + next[ind+1];
            curr[prev_ind+1] = max(take, not_take);
        }
        next = curr; // swap the 2 arrays
    }
    return next[-1+1];
}

// T : O(N^2)
// S : O(N)
int LISTab2(vector<int> arr)
{
    int n = arr.size();
    vector<int> dp (n,1); // each element is a LIS of size 1 by default

    int maxi = 0;
    for(int i = 0; i<n; i++)
    {
        for(int prev = 0; prev<i; prev++)
        {
            if(arr[prev]<arr[i])
            {
                dp[i] = max(dp[prev]+1,dp[i]);
            }
        }
        maxi = max(dp[i], maxi);
    }
    return maxi;
}

int main()
{
    vector<int> arr {10,9,2,5,3,7,101,18};
    int n = arr.size();
    cout<<"recursion : "<<LIS(arr, 0, -1)<<"\n";

    // dp[n][n+1]   ...   ind : 0 -> n-1 ,   prev_ind : -1 -> n-1
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    cout<<"memoization : "<<LISMem(arr, 0, -1, dp)<<"\n";

    cout<<"tabulation : "<<LISTab(arr)<<"\n";

    cout<<"space optimization : "<<LISSO(arr)<<"\n";

    cout<<"Tabulation intuition : "<<LISTab2(arr)<<"\n";
    return 0;
}