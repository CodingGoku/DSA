#include <bits/stdc++.h>
using namespace std;

int rotatedSorted(vector<int> arr, int n, int k)
{
    int low=0, high=n-1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;

        if(arr[mid]==k) return mid;

        // if left side is sorted
        if(arr[low]<=arr[mid])
        {
            if(arr[low]<=k && k<=arr[mid]) // then check it in the left side
            {
                high = mid-1;
            }
            else
            {
                low = mid+1; // if not present in left part then eliminate that left part
            }
        }

        // if right part is sorted
        else
        {
            if(arr[mid]<=k && k<=arr[high]) // then check in the right side
            {
                low = mid+1;
            }
            else
            {
                high = mid-1; // if not present in right part then eliminate that right part
            }
        }
    }
    return -1; // if not found
}

int main()
{
    vector<int> arr {7,8,9,1,2,3,4,5,6};
    int n = arr.size();
    int k = 8;
    cout<<rotatedSorted(arr,n,k);
    return 0;
}