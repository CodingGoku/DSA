#include <bits/stdc++.h>
using namespace std;

// T: O(2^N x N)
// S: ~O(2^N x N) ... total 2^N subsets, but not every subset is of size N
vector<vector<int>> powerSet(vector<int>& arr) {
    int n = arr.size();

    // total subsets
    int subsets = 1 << n; // 2^n
    vector<vector<int>> ans;

    for(int num=0; num<subsets; num++) { // iterating from number 0 to 2^n-1
        vector<int> list = {};
        for(int i=0; i<n; i++) { // binary size is n, we are iterating the binary number's bits
            if(num & 1<<i) list.push_back(arr[i]); // if this bit is set, add this number
        }
        ans.push_back(list);
    }
    return ans;
}

int main()
{
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans = powerSet(arr);
    for(auto it : ans) {
        for(auto i : it) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}