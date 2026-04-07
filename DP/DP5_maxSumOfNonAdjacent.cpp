#include <bits/stdc++.h>
using namespace std;

//Recursion
// T: Exponential S: O(N)+O(N)
int maxSumNonAdj(vector<int> arr,int index)
{
    //base case
    if(index<0) return 0;

    int pick = arr[index]+maxSumNonAdj(arr,index-2); //cant pick the next adjacent element so skip 2
    int not_pick=maxSumNonAdj(arr,index-1); //not picking current element go can go to the next element

    return max(pick,not_pick);
}

//Memoization
// T: O(N) S: O(N)+O(N)
int maxSumNonAdjMem(vector<int> arr, int index, vector<int>& dp)
{
    //base case
    if(index<0) return 0;

    if(dp[index]!=-1) return dp[index];

    int pick = arr[index]+maxSumNonAdj(arr,index-2); //cant pick the next adjacent element so skip 2
    int not_pick=maxSumNonAdj(arr,index-1); //not picking current element go can go to the next element

    dp[index]=max(pick,not_pick);
    return dp[index];
}

//Tabulation
// T: O(N) S: O(N)
int maxSumNonAdjTab(vector<int> arr,int n)
{
    int index=n-1;
    vector<int> dp(n,0);
    //base case
    dp[0]=arr[0];

    for(int i=1;i<n;i++)
    {
        int pick = arr[i]; if(i>1) pick+=dp[i-2]; // if i is 0,1 then dp[i-2] will be a negative index
        int not_pick = dp[i-1];

        dp[i]=max(pick,not_pick);
    }
    return dp[n-1];
}

//Space Optimization
// T: O(N) S: O(1)
int maxSumNonAdjSO(vector<int> arr,int n)
{
    int index=n-1;

    //base case
    int curr,prev1=arr[0],prev2=0; // prev1=arr[0] and not curr because in next step in for loop i in incremented and each moves by 1 step

    for(int i=1;i<n;i++)
    {
        int pick = arr[i]; if(i>1) pick+=prev2; // if i is 0,1 then dp[i-2] will be a negative index
        int not_pick = prev1;

        curr=max(pick,not_pick);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

int main()
{
    vector<int> arr {2,1,4,9};
    int n=arr.size();
    int index=arr.size()-1; //last index
    cout<<maxSumNonAdj(arr,index)<<"\n\n";

    vector<int> dp(n,-1);
    cout<<maxSumNonAdjMem(arr,index,dp)<<"\n\n";

    cout<<maxSumNonAdjTab(arr,n)<<"\n\n";

    cout<<maxSumNonAdjSO(arr,n);
    return 0;
}