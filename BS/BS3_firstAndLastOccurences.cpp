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
            high = mid - 1; // look fo more small index on left
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
            high = mid - 1; // look fo more small index on left
            ans = mid; // update answer
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

// T : O(2 log(N))   ... 2 times as we use lb + ub
// S : O(1)
pair<int,int> firstAndLast(vector<int> arr, int n, int k)
{
    int lb = lowerBound(arr,0,n-1,k,n);
    int ub = upperBound(arr,0,n-1,k,n);
    if(lb==n || arr[lb]!=k) return {-1,-1};
    return {lb,ub-1};
}

// IF THE INTERVIEWER ASKS TO DO WITHOUT LOWER AND UPPER BOUND

// first occurence
int fst(vector<int> arr, int n, int x)
{
    int low=0, high=n-1, first=-1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid]==x)
        {
            first = mid;
            high = mid-1;
        }
        else if(arr[mid] < x)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return first;
}

// last occurence
int lst(vector<int> arr, int n, int x)
{
    int low=0, high=n-1, last=-1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid]==x)
        {
            last = mid;
            low = mid+1;
        }
        else if(arr[mid] > x)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return last;
}

int main()
{
    vector<int> arr {1,2,3,3,3,3,4,5,5};
    int n=arr.size();
    int x=3;
    pair<int,int> p = firstAndLast(arr,n,x);
    cout<<"first : "<<p.first<<"   last : "<<p.second<<"\n\n";

    cout<<"first : "<<fst(arr,n,x)<<"   last : "<<lst(arr,n,x)<<"\n\n";

    cout<<"No. of Occurences of x : "<<(lst(arr,n,x)-fst(arr,n,x)+1); // last - first + 1
    return 0;
}