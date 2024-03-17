#include <bits/stdc++.h>
using namespace std;

// Previous question function modified to return the index of mini
int minimum(vector<int> arr)
{
    int n = arr.size();
    int low=0, high=n-1;
    int mini = INT_MAX;
    int index;
    while(low<=high)
    {
        int mid = low + (high-low)/2;

        // left side is sorted
        if(arr[low]<=arr[mid])
        {
            if(arr[low]<mini)
            {
                mini=arr[low];
                // to find index of mini
                index=low;
            }
            low = mid+1;
        }
        // right side is sorted
        else
        {
            if(arr[mid]<mini)
            {
                mini=arr[mid];
                // to find index of mini
                index=mid;
            }
            high = mid-1;
        }
    }
    return index;
}

int main()
{
    vector<int> arr {6,7,8,9,1,2,3,4,5};
    cout<<minimum(arr);
    return 0;
}