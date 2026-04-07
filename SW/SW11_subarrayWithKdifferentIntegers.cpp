#include <bits/stdc++.h>
using namespace std;

// T: O(N^2)
// S: O(N)
int subarrayWithKdifferentIntegers(vector<int>& arr, int k) {
    int n = arr.size();
    int cnt = 0;
    unordered_map<int, int> freq;

    for(int i=0; i<n; i++) {
        freq.clear();
        for(int j=i; j<n; j++) {
            freq[arr[j]]++;
            if(freq.size() == k) cnt++;
            else if(freq.size() > k) break;
        }
    }

    return cnt;
}

// first finding for subarrays with different integers <= k
// T: O(2N) ... iteration of l and r
// S: O(N) ... map
int subarrayWithKdifferentIntegersOP(vector<int>& arr, int k) {
    int n = arr.size();
    int cnt = 0;
    int l = 0, r = 0;
    unordered_map<int, int> freq;

    while(r < n) {
        freq[arr[r]]++;
        while(freq.size() > k) {
            freq[arr[l]]--;
            if(freq[arr[l]] == 0) freq.erase(arr[l]);

            l++;
        }

        cnt += (r-l+1); // as from current index r, all previous subarrays will be valid i.e. <= k
        r++;
    }

    return cnt;
}

int main()
{
    vector<int> arr = {1,2,1,3,4};
    int k = 3;

    cout<<subarrayWithKdifferentIntegers(arr, k)<<endl;

    int equal = subarrayWithKdifferentIntegersOP(arr, k);
    int less = subarrayWithKdifferentIntegersOP(arr, k-1);
    int res = equal - less;
    cout<<res<<endl;

    return 0;
}