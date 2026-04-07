#include <bits/stdc++.h>
using namespace std;

// T: O(K + K) ... 2 for loops
// S: O(1)
int maxPointsFromCards(vector<int>& arr, int k) {
    int n = arr.size();
    int lsum=0, rsum=0, maxSum=0;

    // sum of first k elements of arr from left
    for(int i=0; i<k; i++) {
        lsum += arr[i];
    }
    maxSum = lsum;

    int r = n-1;
    for(int i=k-1; i>=0; i--) {
        lsum -= arr[i]; // remove from left
        rsum += arr[r]; // add to right
        r--;
        maxSum = max(maxSum,lsum+rsum);
    }

    return maxSum;
}

int main()
{
    vector<int> arr = {6,2,3,4,7,2,1,7,1};
    cout<<maxPointsFromCards(arr,4);
    return 0;
}