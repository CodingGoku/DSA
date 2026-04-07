#include <bits/stdc++.h>
using namespace std;

// Question is to chech if there is a subset sum that equals the target

//Recursion
// T : O(2^N) ... 2 cases take or not take
// S : O(N) ... stack space
bool subsetSum(vector<int>& arr,int index,int target)
{
    //base case
    if(target==0) return true;
    if(index==0) return arr[0]==target; // when we reached the last element i.e. arr[0] we only need to check if arr[0] is equal to target or not

    //TAKE OR NOT TAKE
    bool not_take,take=false;
    not_take=subsetSum(arr,index-1,target); // index will decrement even if element not taken
    if(arr[index]<=target) take=subsetSum(arr,index-1,target-arr[index]); // (if the next element is less than or equal to the target value)
    return not_take | take;                                              // index will be decremented as well as the taken element will be reduced from the target value
}

//Memoization
// T : O(N x Target)
// S : O(N x Target) + O(N) ... stack space
bool subsetSumMem(vector<int>& arr,int index,int target,vector<vector<int>> dp)
{
    //base case
    if(target==0) return true;
    if(index==0) return arr[0]==target; // when we reached the last element i.e. arr[0] we only need to check if arr[0] is equal to target or not

    if(dp[index][target]!=-1) return dp[index][target];

    //TAKE OR NOT TAKE
    bool not_take,take=false;
    not_take=subsetSumMem(arr,index-1,target,dp); // index will decrement even if element not taken
    if(arr[index]<=target) take=subsetSumMem(arr,index-1,target-arr[index],dp); // index will be decremented as well as the taken element will be reduced from the target value
    dp[index][target]=not_take | take;
    return dp[index][target];
}

//Tabulation
// T : O(N x Target)
// S : O(N x Target)
bool subsetSumTab(int n,int k,vector<int> &arr)
{
    vector<vector<bool>> dp(n,vector<bool>(k+1,0)); // dp[index][target]

    for(int i=0;i<n;i++) dp[i][0]=true; // at all index when target is 0 it is true
    dp[0][arr[0]]=true; // when index is 0 and target equal to arr[0] it is true

    for(int index=1;index<n;index++) // index = 0 done in base case so we start with 1
    {
        for(int target=1;target<=k;target++) // target = 0 done in base case so we start with 1
        {
            //paste directly from Memoization and make changes
             bool not_take,take=false;
            not_take=dp[index-1][target];
            if(arr[index]<=target) take=dp[index-1][target-arr[index]];
            dp[index][target]=not_take | take;
        }
    }
    return dp[n-1][k]; // return what was input in recursion
}

//Space Optimization
// T : O(N x Target)
// S : O(Target)
bool subsetSumSO(int n,int k,vector<int> &arr)
{
    vector<bool> prev(k+1,0), curr(k+1,0);

    prev[0]=curr[0]=true; // at all index when target is 0 it is true
    prev[arr[0]]=true; // when index is 0 and target equal to arr[0] it is true

    for(int index=1;index<n;index++) // index = 0 done in base case so we start with 1
    {
        for(int target=1;target<=k;target++) // target = 0 done in base case so we start with 1
        {
            //paste directly from Memoization and make changes
             bool not_take,take=false;
            not_take=prev[target];
            if(arr[index]<=target) take=prev[target-arr[index]];
            curr[target]=not_take | take;
        }
        prev=curr;
    }
    return prev[k]; // return what was input in recursion
}


int main()
{
    vector<int> arr{4,6,4,3,6,1};
    int n=arr.size();
    cout<<subsetSum(arr,n-1,8)<<"\n";
    cout<<subsetSum(arr,n-1,40)<<"\n";
    cout<<subsetSum(arr,n-1,10)<<"\n";
    cout<<subsetSum(arr,n-1,2)<<"\n";
    cout<<subsetSum(arr,n-1,13)<<"\n";

    cout<<"\n";
    int k=9; // k=target
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    cout<<subsetSumMem(arr,n-1,k,dp)<<"\n";
    k=2;
    cout<<subsetSumMem(arr,n-1,k,dp)<<"\n";

    k=9;
    cout<<"\n";
    cout<<subsetSumTab(n-1,k,arr)<<"\n";
    k=2;
    cout<<subsetSumTab(n-1,k,arr)<<"\n";

    k=9;
    cout<<"\n";
    cout<<subsetSumSO(n-1,k,arr)<<"\n";
    k=2;
    cout<<subsetSumSO(n-1,k,arr)<<"\n";
    return 0;
}