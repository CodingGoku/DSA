#include <bits/stdc++.h>
using namespace std;

// Recursion
// T : O(> 2^N) ... exponential
// S : O(> N) ... O(target)
int minimumCoins(vector<int> coins, int ind, int target)
{
    //base case
    if(ind == 0)
        {
            if(target % coins[0] == 0) return target/coins[0]; // if index = 0 and the target is divisible by the last coin then return the number of coins
            else return 1e9;
        }
    int not_take = 0 + minimumCoins(coins, ind-1, target);
    int take = 1e9; // not INT_MAX as it is adding up with +1s
    if(coins[ind] <= target) take = 1 + minimumCoins(coins, ind, target - coins[ind]); // index remains same as same coin can be taken again and again

    return min(take,not_take);
}

// Memoization
// T : O(N x target)
// S : O(N x target) + O(target)
int minimumCoinsMem(vector<int> coins, int ind, int target, vector<vector<int>> dp)
{
    //base case
    if(ind == 0)
        {
            if(target % coins[0] == 0) return target/coins[0]; // if index = 0 and the target is divisible by the last coin then return the number of coins
            else return 1e9;
        }

    if(dp[ind][target] != -1) return dp[ind][target];

    int not_take = 0 + minimumCoins(coins, ind-1, target);
    int take = 1e9; // not INT_MAX as it is adding up with +1s
    if(coins[ind] <= target) take = 1 + minimumCoins(coins, ind, target - coins[ind]); // index remains same as same coin can be taken again and again

    dp[ind][target] = min(take,not_take);
    return dp[ind][target];
}

// Tabulation
// T : O(N x target)
// S : O(N x target)
int minimumCoinsTab(vector<int> coins, int ind, int target)
{
    int n = coins.size();
    int T = target;
    vector<vector<int>> dp(n,vector<int>(T+1,0));

    //base case
    for(int target = 0; target<=T; target++)
    {
        if(target % coins[0] == 0) dp[0][target] = target/coins[0];
        else dp[0][target] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++) // ind : 0 -> n-1 but 0 done in base case
    {
        for(int target = 0; target<=T; target++) // target : 0 -> T
        {
            int not_take = 0 + dp[ind-1][target];
            int take = 1e9; // not INT_MAX as it is adding up with +1s
            if(coins[ind] <= target) take = 1 + dp[ind][target - coins[ind]]; // index remains same as same coin can be taken again and again

            dp[ind][target] = min(take,not_take);
        }
    }
    return dp[ind][target];
}

// Space Optimization
// T : O(N x target)
// S : O(target)
int minimumCoinsSO(vector<int> coins, int ind, int target)
{
    int n = coins.size();
    int T = target;
    vector<int> prev(target+1,0), curr(target+1,0);

    //base case
    for(int target = 0; target<=T; target++)
    {
        if(target % coins[0] == 0) prev[target] = target/coins[0];
        else prev[target] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++) // ind : 0 -> n-1 but 0 done in base case
    {
        for(int target = 0; target<=T; target++) // target : 0 -> T
        {
            int not_take = 0 + prev[target];
            int take = 1e9; // not INT_MAX as it is adding up with +1s
            if(coins[ind] <= target) take = 1 + curr[target - coins[ind]]; // index remains same as same coin can be taken again and again

            curr[target] = min(take,not_take);
        }
        prev=curr;
    }
    return prev[target];
}

int main()
{
    vector<int> coins {9,6,5,1};
    int n = coins.size();
    int target = 11;

    cout<<"recursion : "<<minimumCoins(coins,n-1,target)<<"\n";

    // dp[n][target+1]    index n from 0 to n-1  and  target from 0 to target
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    cout<<"memoization : "<<minimumCoinsMem(coins,n-1,target,dp)<<"\n";

    cout<<"tabulation : "<<minimumCoinsTab(coins,n-1,target)<<"\n";

    cout<<"space optimization : "<<minimumCoinsSO(coins,n-1,target)<<"\n";
    return 0;
}