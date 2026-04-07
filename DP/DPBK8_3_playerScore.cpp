#include <bits/stdc++.h>
using namespace std;

//Player can only score 3,5 or 10 points in one move. Given a total score N find total number
//of unique ways to reach N.

//Recursion
int score(int n)
{
    //base case
    if(n<0) return 0;
    if(n==0) return 1;

    return score(n-3)+score(n-5)+score(n-10);
}

//Memoization
int scoreMem(int n,vector<int> dp)
{
    //base case
    if(n<0) return 0;
    if(n==0) return 1;

    if(dp[n]!=-1) return dp[n];

    dp[n]=score(n-3)+score(n-5)+score(n-10);
    return dp[n];
}

//Tabulation
int scoreTab(int n)
{
    vector<int> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        if(i-3>=0) dp[i]+=dp[i-3];
        if(i-5>=0) dp[i]+=dp[i-5];
        if(i-10>=0) dp[i]+=dp[i-10];
    }
    return dp[n];
}

int main()
{
    cout<<score(15)<<"\n"; // 4 (3 3 3 3 3    5 5 5    5 10    10 5)

    vector<int> dp(15+1,-1);
    cout<<scoreMem(15,dp)<<"\n";

    cout<<scoreTab(15)<<"\n";
    return 0;
}