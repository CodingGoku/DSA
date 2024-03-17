#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> arr, int start, int end, int target)
{
    //base case
    if(start>end) return -1; // not in the array

    int mid = start + (end-start)/2;
    if(target == arr[mid]) return mid;
    if(target > arr[mid]) return bs(arr,mid+1,end,target);
    return bs(arr,start,mid-1,target);
}

int main()
{
    vector<int> arr {1,3,5,7,9,10,23,34,56,78,85,92,101};
    int n=arr.size();
    int target=34;
    cout<<bs(arr,0,n-1,target);
    return 0;
}