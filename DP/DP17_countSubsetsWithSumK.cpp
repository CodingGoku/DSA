#include <bits/stdc++.h>
using namespace std;

//Recursion
int countSubsets(vector<int> arr,int ind, int K)
{
    //base case
    if(K == 0) return 1;  // if target becomes  we got the answer
    if(ind == 0) return arr[0] == K; // if the last element is equal to K then return true else false

    int not_take = countSubsets(arr,ind-1,K);
    int take = 0;
    if(arr[ind] <= K) take = countSubsets(arr,ind-1,K-arr[ind]);

    return not_take + take;
}

//Memoization
int countSubsetsMem(vector<int> arr,int ind, int K, vector<vector<int>> dp)
{
    //base case
    if(K == 0) return 1;  // if target becomes  we got the answer
    if(ind == 0) return arr[0] == K; // if the last element is equal to K then return true else false

    if(dp[ind][K]!=-1) return dp[ind][K];

    int not_take = countSubsets(arr,ind-1,K);
    int take = 0;
    if(arr[ind] <= K) take = countSubsets(arr,ind-1,K-arr[ind]);

    dp[ind][K] = not_take + take;
    return dp[ind][K];
}

//Tabulation
// 1. Base Case
// 2. Nested For Loops
// 3. Paste Memoization in loop
int countSubsetsTab(vector<int> arr, int ind, int K)
{
    int tar = K;
    int n = arr.size();
    vector<vector<int>> dp (n, vector<int> (K+1,0));

    //base case
    for(int i=0; i<n; i++) dp[i][0] = 1; // irrespective of index if K = 0 return 1
    if(arr[0] <= K) dp[0][arr[0]] = 1; // if index is 0 and K is arr[0] return 1;

    for(int ind=1; ind<n; ind++)
    {
        for(int K = 0; K <= tar; K++)
        {
            int not_take = dp[ind-1][K];
            int take = 0;
            if(arr[ind] <= K) take = dp[ind-1][K-arr[ind]];

            dp[ind][K] = not_take + take;
        }
    }
    return dp[n-1][K];
}

//Space Optimization
int countSubsetsSO(vector<int> arr, int ind, int K)
{
    int tar = K;
    int n = arr.size();
    vector<int> prev (K+1,0), curr (K+1,0); // rows

    //base case
    prev[0]=curr[0] = 1;   //for(int i=0; i<n; i++) dp[i][0] = 1;  (every row col = 1 it is 1 )
    if(arr[0] <= K) prev[arr[0]] = 1;

    for(int ind=1; ind<n; ind++)
    {
        for(int K = 0; K <= tar; K++)
        {
            int not_take = prev[K];
            int take = 0;
            if(arr[ind] <= K) take = prev[K-arr[ind]];

            curr[K] = not_take + take;
        }
        prev = curr;
    }
    return prev[K];
}

int main()
{
    vector<int> arr {2,3,5,6,1,8};
    int n = arr.size();
    int K=9;

    cout<<"recursion : "<<countSubsets(arr,n-1,K)<<"\n";

    // d[n][K+1]   index form 0 to n-1   and   target from 0 to K
    vector<vector<int>> dp (n,vector<int> (K+1,-1));
    cout<<"memoization : "<<countSubsetsMem(arr,n-1,K,dp)<<"\n";

    cout<<"tabulation : "<<countSubsetsTab(arr,n-1,K)<<"\n";

    cout<<"space optimization : "<<countSubsetsSO(arr,n-1,K)<<"\n";
    return 0;
}