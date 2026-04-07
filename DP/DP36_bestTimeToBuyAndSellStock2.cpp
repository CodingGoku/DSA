#include <bits/stdc++.h>
using namespace std;

// Recursion
// T : O(2^N)
// S : O(N) auxiliary stack space
int buySell(vector<int> price, int ind, int buy)
{
    //base case
    if(ind == price.size()) return 0; // index > last-index

    int profit = 0;
    if(buy) // buy phase
    {
        profit = max(-price[ind] + buySell(price, ind+1, 0), 0 + buySell(price, ind+1, 1)); // profit = max(-buyPrice + buy, not_buy);
    }
    else // sell phase
    {
        profit = max(price[ind] + buySell(price, ind+1, 1), 0 + buySell(price, ind+1, 0)); // profit = max(sellPrice + sell, not_sell);
    }

    return profit;
}

// Memoization
// T : O(N x 2)
// S : O(N x 2) + O(N) auxiliary stack space
int buySellMem(vector<int> price, int ind, int buy, vector<vector<int>> dp)
{
    //base case
    if(ind == price.size()) return 0; // index > last-index

    if(dp[ind][buy] != -1) return dp[ind][buy];

    int profit = 0;
    if(buy) // buy phase
    {
        profit = max(-price[ind] + buySellMem(price, ind+1, 0, dp), 0 + buySellMem(price, ind+1, 1, dp)); // profit = max(-buyPrice + buy, not_buy);
    }
    else // sell phase
    {
        profit = max(price[ind] + buySellMem(price, ind+1, 1, dp), 0 + buySellMem(price, ind+1, 0, dp)); // profit = max(sellPrice + sell, not_sell);
    }

    return dp[ind][buy] = profit;
}

// Tabulation
// T : O(N x 2)
// S : O(N x 2)
int buySellTab(vector<int> price, int ind, int buy)
{
    int n = price.size();
    vector<vector<int>> dp(n+1, vector<int>(2,0)); // n+1 as we are using dp[n][0] and dp[n][1] in base case ( if(ind == n)

    //base case
    dp[n][0] = dp[n][1] = 0;

    for(int ind = n-1; ind>=0; ind--) // tabulation is reverse of recursion so it starts from n-1 -> 0
    {
        for(int buy = 0; buy<=1; buy++)
        {
            int profit = 0;
            if(buy) // buy phase
            {
                profit = max(-price[ind] + dp[ind+1][0], 0 + dp[ind+1][1]); // profit = max(-buyPrice + buy, not_buy);
            }
            else // sell phase
            {
                profit = max(price[ind] + dp[ind+1][1], 0 + dp[ind+1][0]); // profit = max(sellPrice + sell, not_sell);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

// Space Optimization
// T : O(N x 2)
// S : O(2)
int buySellSO(vector<int> price, int ind, int buy)
{
    int n = price.size();
    vector<int> curr (2,0), next(2,0);

    //base case
    next[0] = next[1] = 0; // can be ommited as it is 0 at start

    for(int ind = n-1; ind>=0; ind--) // tabulation is reverse of recursion so it starts from n-1 -> 0
    {
        for(int buy = 0; buy<=1; buy++)
        {
            int profit = 0;
            if(buy) // buy phase
            {
                profit = max(-price[ind] + next[0], 0 + next[1]); // profit = max(-buyPrice + buy, not_buy);
            }
            else // sell phase
            {
                profit = max(price[ind] + next[1], 0 + next[0]); // profit = max(sellPrice + sell, not_sell);
            }
            curr[buy] = profit;
        }
        next = curr; // the 2 arrays interchange
    }
    return next[1];
}

int main()
{
    vector<int> price {7,1,5,3,6,4};
    int n = price.size();

    cout<<"recursion : "<<buySell(price, 0, 1)<<"\n";

    //dp[n][2]   ... index from 0 to n-1   and buy 0 and 1
    vector<vector<int>> dp(n,vector<int>(2, -1));
    cout<<"memoization : "<<buySellMem(price, 0, 1, dp)<<"\n";

    cout<<"tabulation : "<<buySellTab(price, 0, 1)<<"\n";

    cout<<"space optimization : "<<buySellSO(price, 0, 1)<<"\n";
    return 0;
}