#include <bits/stdc++.h>
using namespace std;

// T: O(N + N) ... outer and inner while loop
// S: O(1)
int binarySubarraysWithSum(vector<int>& arr, int k) {
    int n = arr.size();
    int sum = 0;
    int l = 0, r = 0;
    int cnt = 0;

    // in main function we are calling for `k-1`, so it can go negative
    if(k < 0) return 0; // cannot form sum < 0 with just 0,1

    while(r < n) {
        sum += arr[r];

        while(sum > k) {
            sum -= arr[l];
            l++;
        }
        // now it is a valid subarray with sum <= k
        cnt += (r-l+1); // adding each subarray from r to l as with every element
                        // there is a subarray that ends

        r++;
    }

    return cnt; // Subarrays with sum <= k
}

int main()
{
    vector<int> arr = {1,0,0,1,1,0};
    int k = 2;

    int equal = binarySubarraysWithSum(arr, k); // returns subarray with sum <= k
    int less = binarySubarraysWithSum(arr, k-1); // returns subarray with sum <= k-1
    // we need subarray with sum = k
    // i.e. subarrays with (sum <= k) - (sum <= k-1)
    int res = equal - less;
    cout<<res<<endl;

    return 0;
}