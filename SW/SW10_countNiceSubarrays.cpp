#include <bits/stdc++.h>
using namespace std;

// T: O(N + N) ... outer and inner while loop
// S: O(1)
int countNiceSubarrays(vector<int>& arr, int k) {
    int n = arr.size();
    int l = 0, r = 0;
    int cnt = 0;
    int sum = 0;

    if(k < 0) return 0;

    while(r < n) {
        // only change done to previous question
        sum += arr[r]%2; // adds 1 if odd, else 0

        while(sum > k) {
            sum -= arr[l];
            l++;
        }

        cnt += (r-l+1);
        r++;
    }
    return cnt;
}

int main()
{
    vector<int> arr = {1,5,2,1,1};
    int k = 3;

    int equal = countNiceSubarrays(arr, k);
    int less = countNiceSubarrays(arr, k-1);
    int res = equal - less;
    cout<<res<<endl;
    return 0;
}