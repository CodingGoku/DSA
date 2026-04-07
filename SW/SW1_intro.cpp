#include <bits/stdc++.h>
using namespace std;

// 1. Constant Window
// find max sum with given window size k
int constantWindow(vector<int>& arr, int k) {
    int n = arr.size();
    int l = 0;
    int r = k-1;
    int sum = 0;

    // initial sum
    for(int i=0; i<k; i++) {
        sum += arr[i];
    }

    int maxi = INT_MIN;
    while(r < n-1) { // r < n will be out of boundary
        sum -= arr[l];
        l++;
        r++;
        sum += arr[r];

        maxi = max(maxi, sum);
    }
    return maxi;
}

// 2. Longest Subarray/Substring where <condition>
// find longest subarray with sum <= k

// Brute Force
// T : O(N^2)
// S : O(1)
int longestSubarray(vector<int>& arr, int k) {
    int n = arr.size();

    int maxlen = 0;
    for(int i=0; i<n-1; i++) {
        int sum = 0;
        for(int j=i; j<n-1; j++) {
            sum += arr[j];
            if(sum <= k) {
                maxlen = max(maxlen,j-i+1); // length of subarray is j-i+1
            }
            else break; // if sum exceeds k, there is no point in adding more elements to sum
        }
    }
    return maxlen;
}

// T: O(N + N) ... 1 for expanding(r), 1 for shrinking(l)
// S: O(1)
int longestSubarray2P(vector<int>& arr, int k) {
    int n = arr.size();
    int l=0, r=0, sum=0, maxlen=0;
    
    while(r<n) {
        sum += arr[r];
        
        while(sum > k) { // shrink
            sum -= arr[l];
            l++;
        }

        // now, sum is <= k
        maxlen = max(maxlen, r-l+1);
        r++; // expand
    }
    return maxlen;
}

// T: O(N)
// S: O(1)
int longestSubarray2Pop(vector<int>& arr, int k) {
    int n = arr.size();
    int l=0, r=0, sum=0, maxlen=0;
    
    while(r<n) {
        sum += arr[r];
        
        // CHANGE WHILE -> IF from prev code
        if(sum > k) { // shrink
            sum -= arr[l];
            l++;
        }

        // now, sum is <= k
        maxlen = max(maxlen, r-l+1);
        r++; // expand
    }
    return maxlen;
}

int main()
{
    vector<int> arr = {-1,2,3,3,4,5,-1};
    cout<<constantWindow(arr, 4)<<endl;

    arr = {2,5,1,7,10};
    cout<<longestSubarray(arr, 14)<<endl;

    cout<<longestSubarray2P(arr, 14)<<endl;

    cout<<longestSubarray2Pop(arr, 14)<<endl;
    return 0;
}