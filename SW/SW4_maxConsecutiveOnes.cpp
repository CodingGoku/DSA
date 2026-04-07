#include <bits/stdc++.h>
using namespace std;

// T: O(N^2)
// S: O(1)
int maxConsecutiveOnes(vector<int>& arr, int k) {
    int n = arr.size();
    int maxLen = 0;

    for(int i=0; i<n; i++) {
        int zeroes = 0;
        for(int j=i; j<n; j++) {
            if(arr[j]==0) zeroes++;
            if(zeroes <= k) {
                maxLen = max(maxLen, j-i+1);
            }
            else break; // if zeroes exceeds k then break
        }
    }

    return maxLen;
}


// T: O(N + N)
// S: O(1)
int maxConsecutiveOnesOP(vector<int>& arr, int k) {
    int n = arr.size();
    int maxLen=0, l=0, r=0, zeroes=0;

    while(r<n) {

        if(arr[r] == 0) zeroes++;

        while(zeroes > k) {
            if(arr[l] == 0) zeroes--;
            l++;
        }

        maxLen = max(maxLen, r-l+1);
        r++;
    }

    return maxLen;
}


// T: O(N)
// S: O(1)
int maxConsecutiveOnesSOP(vector<int>& arr, int k) {
    int n = arr.size();
    int maxLen=0, l=0, r=0, zeroes=0;

    while(r<n) {
        if(arr[r] == 0) zeroes++;

        if(zeroes > k) { // if in our window, the zeroes exceeds k, shift l by 1
            if(arr[l] == 0) zeroes--; // decrement zereos if found any
            l++;
        }

        if(zeroes <= k) maxLen = max(maxLen, r-l+1);

        r++;
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout<<maxConsecutiveOnes(arr, k)<<endl;

    cout<<maxConsecutiveOnesOP(arr, k)<<endl;

    cout<<maxConsecutiveOnesSOP(arr, k)<<endl;
    return 0;
}