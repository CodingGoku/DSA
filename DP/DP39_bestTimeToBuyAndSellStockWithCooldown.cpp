#include <bits/stdc++.h>
using namespace std;

// Recursion
// T : O(2^N)
// S : O(N) auxiliary stack space
int buySell(vector<int> price, int ind, int buy, int c)
{
    //base case
    if(ind >= price.size()) return 0; // index >= last-index

    int profit = 0;
    if(buy) // buy phase
    {
        profit = max(-price[ind] + buySell(price, ind+1, 0, c), 0 + buySell(price, ind+1, 1, c)); // profit = max(-buyPrice + buy, not_buy);
    }
    else // sell phase
    {
        profit = max(price[ind] + buySell(price, ind+1+c, 1, c), 0 + buySell(price, ind+1, 0, c)); // profit = max(sellPrice + sell, not_sell);
    }

    return profit;
}

// Memoization
// T : O(N x 2)
// S : O(N x 2) + O(N) auxiliary stack space
int buySellMem(vector<int> price, int ind, int buy, vector<vector<int>> dp, int c)
{
    //base case
    if(ind >= price.size()) return 0;

    if(dp[ind][buy] != -1) return dp[ind][buy];

    int profit = 0;
    if(buy) // buy phase
    {
        profit = max(-price[ind] + buySellMem(price, ind+1, 0, dp, c), 0 + buySellMem(price, ind+1, 1, dp, c));
    }
    else // sell phase
    {
        profit = max(price[ind] + buySellMem(price, ind+1+c, 1, dp, c), 0 + buySellMem(price, ind+1, 0, dp, c));
    }

    return dp[ind][buy] = profit;
}

// Tabulation
// T : O(N x 2)
// S : O(N x 2)
int buySellTab(vector<int> price, int ind, int buy, int c)
{
    int n = price.size();
    vector<vector<int>> dp(n+2, vector<int>(2,0)); // n+2 because in sell we are calling dp[ind+1+c] and if ind = n-1 and c=1 it becomes dp[n+1]

    //base case
    dp[n][0] = dp[n][1] = 0;

    for(int ind = n-1; ind>=0; ind--)
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
                profit = max(price[ind] + dp[ind+1+c][1], 0 + dp[ind+1][0]); // profit = max(sellPrice + sell, not_sell);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

// Space Optimization
// cannot be done , 3 rows will be required as dp[ind], dp[ind+1], dp[ind+2] ... ind+2 when c=1

int main()
{
    vector<int> price {7,1,5,3,6,4};
    int n = price.size();
    int c = 1; // cooldown of 1-day
    cout<<"recursion : "<<buySell(price, 0, 1, c)<<"\n";

    //dp[n][2]   ... index from 0 to n-1   and buy 0 and 1
    vector<vector<int>> dp(n,vector<int>(2, -1));
    cout<<"memoization : "<<buySellMem(price, 0, 1, dp, c)<<"\n";

    cout<<"tabulation : "<<buySellTab(price, 0, 1, c)<<"\n";

    return 0;
}