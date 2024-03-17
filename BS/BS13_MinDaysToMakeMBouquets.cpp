#include <bits/stdc++.h>
using namespace std;

// is it possible to make m bouquets on the given day ?
bool isPossible(vector<int> arr, int day, int k, int m) // day-> current day,  k-> flowers in a bouquet,  m-> min. bouqets required
{
    int bouquets=0;
    int cnt=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]<=day) cnt++;
        else
        {
            bouquets+=(cnt/k);
            cnt=0;
        }
    }
    bouquets+=(cnt/k); // for when last case has bouquets
    if(bouquets>=m) return true;
    return false;
}

int MinDays(vector<int> arr, int k, int m)
{
    int low = *min_element(arr.begin(),arr.end()); // min days to bloom
    int high = *max_element(arr.begin(),arr.end()); // max days to bloom
    // BS from min. days to bloom -> t0 max. days to bloom

    while(low<=high)
    {
        int mid = low + (high - low)/2;

        // could be the answer
        if(isPossible(arr,mid,k,m))
        {
            // ans = mid
            high = mid-1; // try for smaller day
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr {7,7,7,7,13,11,12,7};
    cout<<MinDays(arr,3,2);
    return 0;
}