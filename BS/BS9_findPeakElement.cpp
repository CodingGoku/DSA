#include <bits/stdc++.h>
using namespace std;

int peak(vector<int> arr)
{
    int n = arr.size();
    if(n==1) return 0; // index of peak
    if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;
    
    int low = 1, high = n-2;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])  return mid;//peak
        else if(arr[mid]>arr[mid-1]) low = mid + 1; // increasing slope ... eliminate left as peak on right
        else high = mid - 1; // decreasing slope ... eliminate right as peak on left
    }
    // have to return someting even if code never reaches here as functions expects someting to return
    return -1;
}

int main()
{
    vector<int> arr {1,10,13,7,6,5,4,2,1,0};
    cout<<peak(arr);
    return 0;
}