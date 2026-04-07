#include <bits/stdc++.h>
using namespace std;

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

bool partitionEqualSubsetSum(vector<int> arr)
{
    int totalSum=0;
    int n = arr.size();

    for(int i=0; i<n; i++) totalSum+=arr[i];

    if(totalSum%2) return false; // if totalSum is odd then partition cannot be done i.e. s1 and s2 cannot be same

    int target = totalSum/2;

    // calling previous question function
    return subsetSumSO(n-1,target,arr); // (size of array, target or K, array)
}

int main()
{
    vector<int> arr {1,5,2,4,3,5};
    cout<<partitionEqualSubsetSum(arr);
    return 0;
}