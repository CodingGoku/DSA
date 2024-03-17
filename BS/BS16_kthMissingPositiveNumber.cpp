#include <bits/stdc++.h>
using namespace std;

int kth(vector<int> arr, int k)
{
    int n = arr.size();
    int low = 0, high = n-1;
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        int missing_numbers = arr[mid] - (mid + 1); // current value - ideal value at that position
        if(missing_numbers < k) low = mid + 1;
        else high = mid - 1;
    }
    return high + 1 + k;
}

int main()
{
    vector<int> arr {4,7,9}; //  _ _ _ 4 _ _ 7 _ 9
    cout<<kth(arr,5)<<"\n";

    vector<int> arr2 {4,8,12}; //  _ _ _ 4 _ _ _ 8 _ _ _ 12
    cout<<kth(arr2,2);
    return 0;
}