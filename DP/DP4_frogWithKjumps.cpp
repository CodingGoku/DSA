#include <bits/stdc++.h>
using namespace std;

//Recursion
int K_jumps(vector<int> stairs, int index, int k)
{
    //base case
    if(index==0)
    return 0;

    int val,mini=INT_MAX;
    for(int i=1;i<=k;i++)
    {
        if(index-i >= 0) val=K_jumps(stairs,index-i,k)+abs(stairs[index]-stairs[index-i]); // Make sure index-i does not go negative
        mini=min(mini,val);
    }
    return mini;
}

//Memoization
int K_jumpsMem(vector<int> stairs, int index, int k,vector<int>& dp)
{
    //base case
    if(index==0)
    return 0;

    if(dp[index]!=-1)
    return dp[index];

    int val,mini=INT_MAX;
    for(int i=1;i<=k;i++)
    {
        if(index-i >= 0) val=K_jumps(stairs,index-i,k)+abs(stairs[index]-stairs[index-i]); // Make sure index-i does not go negative
        mini=min(mini,val);
    }
    dp[index]=mini;
    return dp[index];
}

int main()
{
    vector<int> stairs {30,10,60,10,60,50};
    int index=stairs.size()-1;
    cout<<K_jumps(stairs,index,3)<<"\n\n";

    vector<int> dp (7,-1);
    cout<<K_jumpsMem(stairs,index,3,dp);
    return 0;
}