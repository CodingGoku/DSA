#include <bits/stdc++.h>
using namespace std;

//Space Optimization
// T: O(N) S: O(1)
int maxSumNonAdjSO(vector<int> arr)
{
    int n=arr.size();
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

int house_robber(vector<int> arr, int n)
{
    if(n==1) return arr[0];
    vector<int> temp1,temp2;
    for(int i=0;i<n;i++)
    {
        if(i!=0) temp1.push_back(arr[i]); // contains arr except first element
        if(i!=n-1) temp2.push_back(arr[i]); // contains arr except last element
    }
    return max(maxSumNonAdjSO(temp1),maxSumNonAdjSO(temp2));
}

int main()
{
    vector<int> arr {2,1,4,9};
    int n=arr.size();
    cout<<house_robber(arr,n);
    return 0;
}