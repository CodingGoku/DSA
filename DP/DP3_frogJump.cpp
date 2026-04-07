#include <bits/stdc++.h>
using namespace std;

//Recursion
int jump(vector<int> stairs, int index)
{
    //base case
    if(index==0) return 0;
    int left,right;
    left=jump(stairs,index-1)+abs(stairs[index]-stairs[index-1]);
    if(index>1) right=jump(stairs,index-2)+abs(stairs[index]-stairs[index-2]); // at index 1 it can give -ve value so we use if(index>1)
    return min(left,right);
}

//Memoization
int jumpMem(vector<int> stairs, int index, vector<int>& dp)
{
    //base case
    if(index==0) return 0;

    if(dp[index]!=-1) return dp[index];
    int left,right;
    left=jump(stairs,index-1)+abs(stairs[index]-stairs[index-1]);
    if(index>1) right=jump(stairs,index-2)+abs(stairs[index]-stairs[index-2]); // at index 1 it can give -ve value so we use if(index>1)

    dp[index]=min(left,right);
    return dp[index];
}

//Tabulation
int jumpTab(vector<int> stairs, int n)
{
    //base case
    if(n=0) return 0;

    vector<int> dp(n,0);

    dp[0]=0;

    for(int i=1;i<n;i++)
    {
        int left=dp[i-1]+abs(stairs[i]-stairs[i-1]);

        int right=INT_MAX;
        if(i>1) right=dp[i-2]+abs(stairs[i]-stairs[i-2]); // at index 1 it can give -ve value so we use if(index>1)
        dp[i]=min(left,right);
    }

    return dp[n-1];
}

int main()
{
    vector<int> stairs {30,10,60,10,60,50};
    int index=stairs.size()-1;
    cout<<jump(stairs,index)<<"\n\n";

    vector<int> dp(7,-1);
    cout<<jumpMem(stairs,index,dp)<<"\n\n";

    int n=stairs.size();
    cout<<jumpTab(stairs,index);
    return 0;
}