#include <bits/stdc++.h>
using namespace std;

// T: O(N x 32)
// S: O(1)
int singleNumber2(vector<int>& arr) {
    int n = arr.size();
    int ans = 0;
    for(int bitIndex=0; bitIndex<32; bitIndex++) {
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(arr[i] & (1 << bitIndex)) cnt++; // if this bit is set, add to cnt
        }
        if(cnt%3 == 1) ans = ans | 1<<bitIndex; // not a multiple of 3, set this bit
    }
    return ans;
}

// T: O(NlogN + N/3)
// S: O(1)
int singleNumber2OP(vector<int>& arr) {
    int n = arr.size();
    sort(begin(arr), end(arr)); // sort the array

    for(int i=1; i<n; i+=3) { // move by 3 indexes
        if(arr[i] != arr[i-1]) {
            return arr[i-1]; // if not matching then the answer is left of current index
        }
    }
    // if we are out of loop without finding the number then the answer is the last number
    return arr[n-1];
}

// T: O(N)
// S: O(1)
int singleNumber2SOP(vector<int>& arr) {
    int n = arr.size();
    int ones=0, twos = 0;

    for(int i=0; i<n; i++) {
        ones = (ones ^ arr[i]) & ~twos;
        twos = (twos ^ arr[i]) & ~ones;
    }

    return ones;
}

int main()
{
    vector<int> arr = {5,5,5,6,4,4,4};
    cout<<"singleNumber2: "<<singleNumber2(arr)<<endl;
    cout<<"singleNumber2OP: "<<singleNumber2OP(arr)<<endl;
    cout<<"singleNumber2SOP: "<<singleNumber2SOP(arr)<<endl;
    return 0;
}