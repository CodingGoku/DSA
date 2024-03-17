#include <bits/stdc++.h>
using namespace std;

int single(vector<int> arr)
{
    int n = arr.size();
    if(n==1) return arr[0];
    if(arr[0]!=arr[1]) return arr[0]; // for first element
    if(arr[n-1]!=arr[n-2]) return arr[n-1]; // for secont element
    // apply BS from arr[1] to arr [n-2]
    int low=1, high=n-2;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        // if element is unique
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return arr[mid];

        // element is in right side ... eliminate left side
        if((mid%2==1 && arr[mid]==arr[mid-1]) || (mid%2==0 && arr[mid]==arr[mid+1])) low = mid + 1;
        // element is in left side ... eliminate right side
        else high = mid - 1;
    }
    // have to return someting even if code never reaches here as functions expects someting to return
    return -1;
}

int main()
{
    vector<int> arr {1,1,2,2,3,3,4,5,5,6,6};
    cout<<single(arr);
    return 0;
}