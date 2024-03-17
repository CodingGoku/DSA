#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> arr, int reqCows, int gap)
{
    int cows = 1; // placed at index 0 as no cow before
    int last = arr[0]; // lst cow placed
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]-last >= gap)
        {
            cows++;
            last = arr[i];
        }
        if(cows==reqCows) return true;
    }
    return false;
}


// T : O(log(max - min) X O(N))   ... for BS[1 -> (max-min)] and inside function canWePlace()
// The minimum gap between cows should be maximized
int aggCows(vector<int> arr, int reqCows)
{
    // decide gap using BS [1 -> (max - min)]
    int low = 1, high = *max_element(arr.begin(),arr.end()) - *min_element(arr.begin(),arr.end());

    while(low<=high)
    {
        int mid = low + (high - low)/2;
        if(canWePlace(arr,reqCows,mid)) low = mid + 1;
        else high = mid - 1;
    }
    return high; // as high is going from impossible to possible polarity
}

int main()
{
    vector<int> arr {0,3,4,7,9,10};
    cout<<aggCows(arr,4);
    return 0;
}