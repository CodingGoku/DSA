#include <bits/stdc++.h>
using namespace std;

// Recursion
// T: exponential
// S: O(N) i.e. O(rod_lenght)
int rodCutting(vector<int> &price, int ind, int N)
{
    //base case
    if(ind == 0)
    {
        return N*price[0]; // returns 0 if rod length is already 0 and if some lenght is left say 12 then returns 12*price[0] or price to cut into 12 pieces of lenght 1 each
    }
    int not_take = 0 + rodCutting(price, ind-1, N);
    int take = -1e9;
    int rodLength = ind + 1; //  e.g. if ind is 0 rodLenght is 1
    if(rodLength <= N) take = price[ind] + rodCutting(price, ind, N-rodLength); // as we can take again and again so index remains same
    return max(take,not_take);
}

// Memoization
// T : O(n x N)
// S : O(n x N) + O(target) recursion stack space
int rodCuttingMem(vector<int> &price, int ind, int N, vector<vector<int>> dp)
{
    //base case
    if(ind == 0)
    {
        return N*price[0]; // returns 0 if rod length is already 0 and if some lenght is left say 12 then returns 12*price[0] or price to cut into 12 pieces of lenght 1 each
    }

    if(dp[ind][N] != -1) return dp[ind][N];

    int not_take = 0 + rodCutting(price, ind-1, N);
    int take = -1e9;
    int rodLength = ind + 1; //  e.g. if ind is 0 rodLenght is 1
    if(rodLength <= N) take = price[ind] + rodCutting(price, ind, N-rodLength); // as we can take again and again so index remains same
    
    dp[ind][N] = max(take,not_take);
    return dp[ind][N];
}

// Tabulation
// T : O(n x N)
// S : O(n x N)
int rodCuttingTab(vector<int> &price, int ind, int N)
{
    int n = price.size();
    int rod_length = N;
    vector<vector<int>> dp(n,vector<int>(N+1,0));

    //base case
    for(int N = 0; N <= rod_length; N++) dp[0][N] = N*price[0];

    for(int ind = 1; ind < n; ind++) // index is from 0 -> n-1  ans ind = 0 done in base case
    {
        for(int N = 0; N <= rod_length; N++) // rod_lenght is from 0 -> N
        {
            int not_take = 0 + dp[ind-1][N];
            int take = -1e9;
            int rodLength = ind + 1; //  e.g. if ind is 0 rodLenght is 1
            if(rodLength <= N) take = price[ind] + dp[ind][N-rodLength]; // as we can take again and again so index remains same
            
            dp[ind][N] = max(take,not_take);
        }
    }
    return dp[ind][N];
}

// Space Optimization
// T : O(n x N)
// S : O(N)
int rodCuttingSO(vector<int> &price, int ind, int N)
{
    int n = price.size();
    int rod_length = N;
    vector<int> prev(N+1,0), curr(N+1,0);

    //base case
    for(int N = 0; N <= rod_length; N++) prev[N] = N*price[0];

    for(int ind = 1; ind < n; ind++) // index is from 0 -> n-1  ans ind = 0 done in base case
    {
        for(int N = 0; N <= rod_length; N++) // rod_lenght is from 0 -> N
        {
            int not_take = 0 + prev[N];
            int take = -1e9;
            int rodLength = ind + 1; //  e.g. if ind is 0 rodLenght is 1
            if(rodLength <= N) take = price[ind] + curr[N-rodLength]; // as we can take again and again so index remains same
            
            curr[N] = max(take,not_take);
        }
        prev = curr;
    }
    return prev[N];
}

int main()
{
    // lenght of the rod
    int N = 5;
    vector<int> price {2,5,7,8,10};
    int n  = price.size();

    cout<<"recursion : "<<rodCutting(price, n-1, N)<<"\n";

    // dp[n][N+1]
    vector<vector<int>> dp(n,vector<int>(N+1,-1)); //  index from 0 -> n-1    and   rod_lenght from 0 -> N
    cout<<"memoization : "<<rodCuttingMem(price, n-1, N, dp)<<"\n";

    cout<<"tabulation : "<<rodCuttingTab(price, n-1, N)<<"\n";

    cout<<"space optimization : "<<rodCuttingSO(price, n-1, N)<<"\n";

    return 0;
}