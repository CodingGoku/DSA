// 0/1 Knapsack

#include <bits/stdc++.h>
using namespace std;

//Recursion
// T : O(2^N) exponential
// S : O(N)
int knapsack(int ind, int W, vector<int> &wt, vector<int> &val)
{
    //base case
    if(ind == 0)
    {
        if(wt[0] <= W) return val[0]; // if at last index return last weight steal if weight space
        return 0; // else return 0 as cant steal if no space in the bag
    }

    int not_take = 0 + knapsack(ind-1,W,wt,val); // if not taken anything it should return 0
    int take = INT_MIN; // if not taken then it should not be considered in max function
    if(wt[ind] <= W) take = val[ind] + knapsack(ind-1,W-wt[ind],wt,val);

    return max(take,not_take);
}

//Memoization
// T : O(N x W)
// S : O(N x W) + O(N) recursion stack space
int knapsackMem(int ind, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> dp)
{
    //base case
    if(ind == 0)
    {
        if(wt[0] <= W) return val[0]; // if at last index return last weight steal if weight space
        return 0; // else return 0 as cant steal if no space in the bag
    }

    if(dp[ind][W] != -1) return dp[ind][W];

    int not_take = 0 + knapsack(ind-1,W,wt,val); // if not taken anything it should return 0
    int take = INT_MIN; // if not taken then it should not be considered in max function
    if(wt[ind] <= W) take = val[ind] + knapsack(ind-1,W-wt[ind],wt,val);

    dp[ind][W] = max(take,not_take);
    return dp[ind][W];
}

//Tabulation
// T : O(N x W)
// S : O(N x W)
int knapsackTab(int ind, int W, vector<int> &wt, vector<int> &val)
{
    int MaxWt = W;
    int n = wt.size();
    vector<vector<int>> dp(n,vector<int>(W+1,0));

    //base case
    for(int W=wt[0]; W<=MaxWt; W++) dp[0][W] = val[0]; // n = 0 done ... n is index

    for(int ind = 1; ind<n; ind++) // n from 1 to n-1
    {
        for(int W = 0; W<=MaxWt; W++) // W from 0 to W
        {
            int not_take = 0 + dp[ind-1][W];
            int take = INT_MIN;
            if(wt[ind] <= W) take = val[ind] + dp[ind-1][W-wt[ind]];

            dp[ind][W] = max(take,not_take);
        }
    }
    return dp[ind][W];
}

//Space Optimization
// T : O(N x W)
// S : O(W)
int knapsackSO(int ind, int W, vector<int> &wt, vector<int> &val)
{
    int MaxWt = W;
    int n = wt.size();
    vector<int> prev(W+1,0), curr(W+1,0);

    //base case
    for(int W=wt[0]; W<=MaxWt; W++) prev[W] = val[0]; // n = 0 done ... n is index

    for(int ind = 1; ind<n; ind++) // n from 1 to n-1
    {
        for(int W = 0; W<=MaxWt; W++) // W from 0 to W
        {
            int not_take = 0 + prev[W];
            int take = INT_MIN;
            if(wt[ind] <= W) take = val[ind] + prev[W-wt[ind]];

            curr[W] = max(take,not_take);
        }
        prev = curr;
    }
    return prev[W];
}

//Single Array Space Optimization
int knapsack1SO(int ind, int W, vector<int> &wt, vector<int> &val)
{
    int MaxWt = W;
    int n = wt.size();
    vector<int> prev(W+1,0);

    //base case
    for(int W=wt[0]; W<=MaxWt; W++) prev[W] = val[0]; // n = 0 done ... n is index

    for(int ind = 1; ind<n; ind++) // n from 1 to n-1
    {
        for(int W = MaxWt; W>=0; W--) // W from 0 to W  // REVERSE IT TO MAXWT TO 0 AND W-- as it doesn't matter as we  were earlier depend on last row not current row elements
        {
            int not_take = 0 + prev[W];
            int take = INT_MIN;
            if(wt[ind] <= W) take = val[ind] + prev[W-wt[ind]];

            prev[W] = max(take,not_take);
        }
    }
    return prev[W];
}

int main()
{
    // bag size is 6
    int W = 6;
    vector<int> wt {3,2,5};
    vector<int> val {30,40,60};

    int n = wt.size();

    cout<<"recursion : "<<knapsack(n-1,6,wt,val)<<"\n";

    // dp[n][W+1]   .... n -> 0 to n-1  &  W+1 -> 0 to W
    vector<vector<int>> dp(n, vector<int> (W+1,-1));
    cout<<"memoization : "<<knapsackMem(n-1,6,wt,val,dp)<<"\n";

    cout<<"tabulation : "<<knapsackTab(n-1,6,wt,val)<<"\n";

    cout<<"space optimization : "<<knapsackSO(n-1,6,wt,val)<<"\n";

    cout<<"single array space optimization : "<<knapsack1SO(n-1,6,wt,val)<<"\n";
    return 0;
}