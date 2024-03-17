#include <bits/stdc++.h>
using namespace std;

int minimum(vector<int> arr)
{
    int n = arr.size();
    int low=0, high=n-1;
    int mini = INT_MAX;
    while(low<=high)
    {
        int mid = low + (high-low)/2;

        // left side is sorted
        if(arr[low]<=arr[mid])
        {
            mini=min(mini,arr[low]);
            low = mid+1;
        }
        // right side is sorted
        else
        {
            mini = min(mini,arr[mid]);
            high = mid-1;
        }
    }
    return mini;
}

int main()
{
    vector<int> arr {7,8,9,1,2,3,4,5,6};
    cout<<minimum(arr);
    return 0;
}