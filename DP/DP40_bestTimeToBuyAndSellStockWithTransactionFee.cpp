#include <bits/stdc++.h>
using namespace std;

// Recursion
// T : O(2^N)
// S : O(N) auxiliary stack space
int buySell(vector<int> price, int ind, int buy, int fee)
{
    //base case
    if(ind == price.size()) return 0; // index > last-index

    if(buy) // buy phase
    {
        return max(-price[ind] + buySell(price, ind+1, 0, fee), 0 + buySell(price, ind+1, 1, fee)); // profit = max(-buyPrice + buy, not_buy);
    }
    else // sell phase
    {
        return max(price[ind] - fee + buySell(price, ind+1, 1, fee), 0 + buySell(price, ind+1, 0, fee)); // profit = max(sellPrice + sell, not_sell);
    }
}

// Memoization
// T : O(N x 2)
// S : O(N x 2) + O(N) auxiliary stack space
int buySellMem(vector<int> price, int ind, int buy, vector<vector<int>> dp, int fee)
{
    //base case
    if(ind == price.size()) return 0; // index > last-index

    if(dp[ind][buy] != -1) return dp[ind][buy];

    if(buy) // buy phase
    {
        return dp[ind][buy] = max(-price[ind] + buySell(price, ind+1, 0, fee), 0 + buySell(price, ind+1, 1, fee)); // profit = max(-buyPrice + buy, not_buy);
    }
    else // sell phase
    {
        return dp[ind][buy] = max(price[ind] - fee + buySell(price, ind+1, 1, fee), 0 + buySell(price, ind+1, 0, fee)); // profit = max(sellPrice + sell, not_sell);
    }
}

// Tabulation
// T : O(N x 2)
// S : O(N x 2)
int buySellTab(vector<int> price, int ind, int buy, int fee)
{
    int n = price.size();
    vector<vector<int>> dp(n+1, vector<int>(2,0)); // n+1 as we are using dp[n][0] and dp[n][1] in base case ( if(ind == n)

    //base case
    dp[n][0] = dp[n][1] = 0;

    for(int ind = n-1; ind>=0; ind--) // tabulation is reverse of recursion so it starts from n-1 -> 0
    {
        for(int buy = 0; buy<=1; buy++)
        {
            if(buy) // buy phase
            {
                dp[ind][buy] = max(-price[ind] + dp[ind+1][0], 0 + dp[ind+1][1]); // profit = max(-buyPrice + buy, not_buy);
            }
            else // sell phase
            {
                dp[ind][buy] = max(price[ind] - fee + dp[ind+1][1], 0 + dp[ind+1][0]); // profit = max(sellPrice + sell, not_sell);
            }
        }
    }
    return dp[0][1];
}

// Space Optimization
// T : O(N x 2)
// S : O(2)
int buySellSO(vector<int> price, int ind, int buy, int fee)
{
    int n = price.size();
    vector<int> curr (2,0), next(2,0);

    //base case
    next[0] = next[1] = 0; // can be ommited as it is 0 at start

    for(int ind = n-1; ind>=0; ind--) // tabulation is reverse of recursion so it starts from n-1 -> 0
    {
        for(int buy = 0; buy<=1; buy++)
        {
            if(buy) // buy phase
            {
                curr[buy] = max(-price[ind] + next[0], 0 + next[1]); // profit = max(-buyPrice + buy, not_buy);
            }
            else // sell phase
            {
                curr[buy] = max(price[ind] -fee + next[1], 0 + next[0]); // profit = max(sellPrice + sell, not_sell);
            }
        }
        next = curr; // the 2 arrays interchange
    }
    return next[1];
}

int main()
{
    vector<int> price {1,3,2,8,4,9};
    int n = price.size();
    int fee = 2;

    cout<<"recursion : "<<buySell(price, 0, 1, fee)<<"\n";

    //dp[n][2]   ... index from 0 to n-1   and buy 0 and 1
    vector<vector<int>> dp(n,vector<int>(2, -1));
    cout<<"memoization : "<<buySellMem(price, 0, 1, dp, fee)<<"\n";

    cout<<"tabulation : "<<buySellTab(price, 0, 1, fee)<<"\n";

    cout<<"space optimization : "<<buySellSO(price, 0, 1, fee)<<"\n";
    return 0;
}