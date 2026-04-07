#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr {5,3,1,11,16,8};
    int n = arr.size();
    vector<int> dp (n,1);

    int maxi = 0;
    for(int i = 0; i<n; i++)
    {
        for(int prev = 0; prev<i; prev++)
        {
            if(arr[prev]<arr[i])
            {
                dp[i] = max(dp[prev]+1,dp[i]);
            }
        }
        maxi = max(dp[i], maxi);
    }
    cout<<maxi;
    return 0;
}