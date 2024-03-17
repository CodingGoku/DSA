#include <bits/stdc++.h>
using namespace std;

int hrsAtK(vector<int> arr, int k) // hours taken to eat all bananas at rate K
{
    int total=0;
    for(int i : arr)
    {
        total+=ceil((double)i/k); // convert to double as int/int will give int, otherwise ceil will get an int to convert to int
    }
    return total; // total hrs taken at k bananas/hr
}

// T : O(n X log(max_element)) ... n for hrsAtK and log(max_element) for BS from 1 to max_element
int koko(vector<int> arr, int h)
{
    int low=1, high = *max_element(arr.begin(),arr.end()); // " * " as it returns an iterator
    int ans = -1;
    while(low<=high)
    {
        int mid = low + (high - low)/2; // here mid is the K value to find
        // could be an answer
        if(hrsAtK(arr,mid)<=h)
        {
            ans = mid;
            high = mid - 1; // we want to find minimum value of k (mid)
        }
        else // if > h
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr {3,6,7,11};
    // 8 hrs
    cout<<koko(arr,8);
    return 0;
}