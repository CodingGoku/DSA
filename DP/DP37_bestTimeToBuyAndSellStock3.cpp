#include <bits/stdc++.h>
using namespace std;

// Recursion
// T : O(2^N)
// S : O(N) auxiliary stack space
int buySell(vector<int> price, int ind, int buy, int cap)
{
    //base case
    if(cap == 0) return 0; // cap is the max no. of buy-sell transactions
    if(ind == price.size()) return 0; // index > last-index

    if(buy) // buy phase
    {
        return max(-price[ind] + buySell(price, ind+1, 0, cap), 0 + buySell(price, ind+1, 1, cap)); // profit = max(-buyPrice + buy, not_buy);
    }
    else // sell phase
    {
        return max(price[ind] + buySell(price, ind+1, 1, cap-1), 0 + buySell(price, ind+1, 0, cap)); // profit = max(sellPrice + sell, not_sell);
    }
}

// Memoization
// T : O(N x 2 x 3)
// S : O(N x 2 x 3) + O(N) auxiliary stack space
int buySellMem(vector<int> price, int ind, int buy, int cap, vector<vector<vector<int>>> dp)
{
    //base case
    if(cap == 0) return 0;
    if(ind == price.size()) return 0;

    if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

    if(buy) // buy phase
    {
        dp[ind][buy][cap] = max(-price[ind] + buySellMem(price, ind+1, 0, cap, dp), 0 + buySellMem(price, ind+1, 1, cap, dp)); // profit = max(-buyPrice + buy, not_buy);
    }
    else // sell phase
    {
        dp[ind][buy][cap] = max(price[ind] + buySellMem(price, ind+1, 1, cap-1, dp), 0 + buySellMem(price, ind+1, 0, cap, dp)); // profit = max(sellPrice + sell, not_sell);
    }

    return dp[ind][buy][cap];
}

// Tabulation
// T : O(N x 2 x 3)
// S : O(N x 2 x 3)
int buySellTab(vector<int> price, int ind, int buy, int cap)
{
    int n = price.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2,vector<int>(3,0)));

    //base case   ... NO NEED THOUGH AS ALREADY 0
            for(int i = 0; i<=2; i++) dp[n][0][i] = dp[n][1][i] = 0; // irrespective of buy and cap when index is n
            for(int i = 0; i<n; i++) // index
            {
                for(int j = 0; j<=1; j++) // buy
                {
                    dp[i][j][0] = 0; // when cap is 0
                }
            }

    for(int ind = n-1; ind>=0; ind--) // tabulation is reverse of recursion so it starts from n-1 -> 0
    {
        for(int buy = 0; buy<=1; buy++)
        {
            for(int cap = 1; cap<=2; cap++) // cap 0 done in base case
            {

                if(buy) // buy phase
                {
                    dp[ind][buy][cap] = max(-price[ind] + dp[ind+1][0][cap], 0 + dp[ind+1][1][cap]); // profit = max(-buyPrice + buy, not_buy);
                }
                else // sell phase
                {
                    dp[ind][buy][cap] = max(price[ind] + dp[ind+1][1][cap-1], 0 + dp[ind+1][0][cap]); // profit = max(sellPrice + sell, not_sell);
                }
            }
        }
    }
    return dp[0][1][2];
}

// Space Optimization
// T : O(N x 2 x 3)
// S : O(2 x 3)
int buySellSO(vector<int> price, int ind, int buy, int cap)
{
    int n = price.size();
    vector<vector<int>> after (2,vector<int>(3,0)), curr (2,vector<int>(3,0));

    for(int ind = n-1; ind>=0; ind--)
    {
        for(int buy = 0; buy<=1; buy++)
        {
            for(int cap = 1; cap<=2; cap++)
            {

                if(buy)
                {
                    curr[buy][cap] = max(-price[ind] + after[0][cap], 0 + after[1][cap]);
                }
                else
                {
                    curr[buy][cap] = max(price[ind] + after[1][cap-1], 0 + after[0][cap]);
                }
            }
            after = curr; // swap the 2 arrays
        }
    }
    return after[1][2];
}

int main()
{
    vector<int> price {3,3,5,0,0,3,1,4};
    int n = price.size();
    int cap = 2;

    cout<<"recursion : "<<buySell(price, 0, 1, cap)<<"\n";

    //dp[n][2][3]   ... index from 0 to n-1   and   buy (0, 1)   cap(0,1,2)
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2, vector<int>(3,-1)));
    cout<<"memoization : "<<buySellMem(price, 0, 1, cap, dp)<<"\n";

    cout<<"tabulation : "<<buySellTab(price, 0, 1, cap)<<"\n";

    cout<<"space optimization : "<<buySellSO(price, 0, 1, cap)<<"\n";
    return 0;
}