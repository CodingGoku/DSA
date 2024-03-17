#include <bits/stdc++.h>
using namespace std;

// With duplicates
bool rotatedSorted(vector<int> arr, int n, int k)
{
    int low=0, high=n-1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;

        if(arr[mid]==k) return true;

        // NEW CONDITION THAT IS ADDED
        if(arr[low]==arr[mid] && arr[mid]==arr[high])
        {
            low++;
            high--;
            continue; // we continue because there can be more
        }

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
    return false; // if not found
}

int main()
{
    vector<int> arr {3,3,3,2,3};
    int n = arr.size();
    int k = 2;
    cout<<rotatedSorted(arr,n,k);
    return 0;
}