#include <bits/stdc++.h>
using namespace std;

int days(vector<int> arr, int cap)
{
    int load=0,day=1;
    for(int i=0;i<arr.size();i++)
    {
        if(load+arr[i]>cap) // if greater than capacity
        {
            day++;      // go to next day
            load = arr[i];      //load on next day
        }
        else load+=arr[i]; // otherwise load on same say
    }
    return day;
}

// T : O(log(sum-max_element+1) X N) ... BS [max_element -> sum] and inside is function days [0->n-1]
int capacity(vector<int> arr, int ReqDays)
{
    int low = *max_element(arr.begin(),arr.end()); // max of arr
    int high = accumulate(arr.begin(), arr.end(), 0); // sum of all of arr

    while(low<=high)
    {
        int mid = low + (high - low)/2;
        if(days(arr,mid)<=ReqDays) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> arr {1,2,3,4,5,6,7,8,9,10};
    cout<<capacity(arr,5);
    return 0;
}