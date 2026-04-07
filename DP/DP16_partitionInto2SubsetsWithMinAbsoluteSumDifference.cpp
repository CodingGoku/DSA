// ***IMPORTANT QUESTION***

#include <bits/stdc++.h>
using namespace std;

int minSumDiff(vector<int> arr)
{
    int n = arr.size();

    int totSum = 0;
    for(int i=0; i<n; i++) totSum += arr[i];

    int k = totSum; // K is target

    // DP 14 code starts
    vector<vector<bool>> dp(n,vector<bool>(k+1,0)); // dp[index][target]

    for(int i=0;i<n;i++) dp[i][0]=true; // at all index when target is 0 it is true
    dp[0][arr[0]]=true; // when index is 0 and target equal to arr[0] it is true

    for(int index=1;index<n;index++) // index = 0 done in base case so we start with 1
    {
        for(int target=1;target<=k;target++) // target = 0 done in base case so we start with 1
        {
            //paste directly from Memoization and make changes
             bool not_take,take=false;
            not_take=dp[index-1][target];
            if(arr[index]<=target) take=dp[index-1][target-arr[index]];
            dp[index][target]=not_take | take;
        }
    }
    // DP 14 code ends

    // dp[n-1][col -> 0 to totSum]
    int mini = 1e9;
    for(int s1 = 0; s1<=totSum/2; s1++)
    {
        if(dp[n-1][s1] == true) // dp[last row][column 0,1,2,...]
        {
            mini = min(mini,abs((totSum-s1) - s1)); // abs(s2 - s1)
        }
    }
    return mini;
}

int main()
{
    vector<int> arr{4,6,4,3,6,1};
    cout<<minSumDiff(arr);
    return 0;
}