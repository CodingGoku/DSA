#include <bits/stdc++.h>
using namespace std;

// Recursion
// T : exponential ... >> O(2^N) as we are at the same index in the take case
// S : O(target) ... >> O(N) as we are at the same index in the take case
int targetSum(vector<int> arr, int ind, int target)
{
    //base case
    if(ind == 0)
    {
        return target % arr[0] == 0; // returns 1 if divisible by last coin else 0
    }

    int not_take = targetSum(arr, ind-1,target);
    int take = 0;
    if(arr[ind]<=target) take = targetSum(arr,ind,target-arr[ind]); // index will not decrease as 1 coin can be taken again and again

    return take+not_take;
}

// Memoization
// T : O(N x target)
// S : O(N x target) + O(target) recusrion stack space
int targetSumMem(vector<int> arr, int ind, int target, vector<vector<int>> dp)
{
    //base case
    if(ind == 0)
    {
        return target % arr[0] == 0; // returns 1 if divisible by last coin else 0
    }

    if(dp[ind][target] != -1) return dp[ind][target];

    int not_take = targetSum(arr, ind-1,target);
    int take = 0;
    if(arr[ind]<=target) take = targetSum(arr,ind,target-arr[ind]); // index will not decrease as 1 coin can be taken again and again

    dp[ind][target] = take+not_take;
    return dp[ind][target];
}

// Tabulation
// T : O(N x target)
// S : O(N x target)
int targetSumTab(vector<int> arr, int ind, int target)
{
    int n = arr.size();
    int T = target;
    vector<vector<int>> dp(n,vector<int>(T+1,0));

    //base case
    for(int target = 0; target<=T; target++) dp[0][target] = (target % arr[0] == 0);

    for(int ind = 1; ind<n; ind++) // index is from 0 -> n-1 and 0 done in base case
    {
        for(int target = 0; target<=T; target++)
        {
            int not_take = dp[ind-1][target];
            int take = 0;
            if(arr[ind]<=target) take = dp[ind][target-arr[ind]]; // index will not decrease as 1 coin can be taken again and again

            dp[ind][target] = take+not_take;
        }
    }
    return dp[ind][target];
}

// Space Optimization
// T : O(N x target)
// S : O(target)
int targetSumSO(vector<int> arr, int ind, int target)
{
    int n = arr.size();
    int T = target;
    vector<int> prev(target+1,0), curr(target+1,0);

    //base case
    for(int target = 0; target<=T; target++) prev[target] = (target % arr[0] == 0);

    for(int ind = 1; ind<n; ind++) // index is from 0 -> n-1 and 0 done in base case
    {
        for(int target = 0; target<=T; target++)
        {
            int not_take = prev[target];
            int take = 0;
            if(arr[ind]<=target) take = curr[target-arr[ind]]; // index will not decrease as 1 coin can be taken again and again

            curr[target] = take+not_take;
        }
        prev = curr;
    }
    return prev[target];
}

int main()
{
    vector<int> arr {1,2,3};
    int n = arr.size();
    int target = 4;

    cout<<"recursion : "<<targetSum(arr,n-1,4)<<"\n";

    // dp[N][target+1]  index from 0 -> N-1    and     target from 0 -> T
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    cout<<"memoization : "<<targetSumMem(arr,n-1,4,dp)<<"\n";

    cout<<"tabulation : "<<targetSumTab(arr,n-1,4)<<"\n";

    cout<<"space optimization : "<<targetSumSO(arr,n-1,4)<<"\n";
    return 0;
}