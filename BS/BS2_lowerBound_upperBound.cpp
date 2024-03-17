#include <bits/stdc++.h>
using namespace std;

// Lower Bound : arr[mid] >= x
int lowerBound(vector<int> arr, int low, int high,int x, int ans)
{
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        // maybe an answer
        if(arr[mid] >= x)
        {
            high = mid - 1; // look for more small index/value on left
            ans = mid; // update answer
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

// Upper Bound : arr[mid] > x
int upperBound(vector<int> arr, int low, int high,int x, int ans)
{
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        // maybe an answer
        if(arr[mid] > x)
        {
            high = mid - 1; // look for more small index/value on left
            ans = mid; // update answer
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

// Floor : largest no. in array <= x
int floor(vector<int> arr, int low, int high,int x, int ans)
{
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        // maybe an answer
        if(arr[mid] <= x)
        {
            low = mid + 1; // look for more big value on right
            ans = mid; // update answer
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

// Ceil : smallest no. in array >= x
int ceil(vector<int> arr, int low, int high,int x, int ans)
{
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        // maybe an answer
        if(arr[mid] >= x)
        {
            high = mid - 1; // look for more small index on left
            ans = mid; // update answer
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr {1,2,3,3,4,5,5,6,8};
    int n=arr.size();
    int x=3;
    int ans = n; // hypothetical if not found
    int low = 0, high = n-1;

    // lower bound
    cout<<"lower bound : "<<lowerBound(arr,low,high,x,ans)<<"\n";

    cout<<"upper bound : "<<upperBound(arr,low,high,x,ans)<<"\n";

    cout<<"floor : "<<floor(arr,low,high,7,ans)<<"\n";

    cout<<"ceil : "<<ceil(arr,low,high,7,ans)<<"\n";
    return 0;
}