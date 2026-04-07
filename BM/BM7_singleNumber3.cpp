#include <bits/stdc++.h>
using namespace std;

// T: O(2N)
// S: O(1)
pair<int,int> singleNumber3(vector<int>& arr) {
    int n = arr.size();
    int xorr = 0;
    for(int i=0; i<n; i++) {
        xorr = xorr ^ arr[i];
    }
    // now xorr has the xor of the 2 numbers we need
    // the rightmost set bit in xorr indicates the different bit in the 2 numbers
    int rightmost = (xorr & xorr-1) ^ xorr; // xorr & xorr-1 removes the rightmost bit, ^ xorr sets only the rightmost bit

    int b1 = 0;
    int b2 = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] & rightmost) b1 = b1 ^ arr[i]; // inserts all numbers where bit is set at position rightmost
        else b2 = b2 ^ arr[i]; // inserts all numbers where bit is not set at position rightmost
    }

    return {b1,b2};
}

int main()
{
    vector<int> arr = {2,4,2,14,8,7,7,8};
    pair<int,int> p = singleNumber3(arr);
    cout<<"single numbers: "<<p.first<<" "<<p.second<<endl;
    return 0;
}