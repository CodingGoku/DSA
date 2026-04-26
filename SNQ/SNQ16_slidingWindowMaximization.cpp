#include <bits/stdc++.h>
using namespace std;

// T: 2N ... N traversal, N while-loop pop N elements
// S: K + (N-K) ... dq and res
vector<int> windowMax(vector<int>& arr, int k) {
    int n = arr.size();
    deque<int> dq;
    vector<int> res;

    for(int i=0; i<n; i++) {
        // remove out of window elements
        if(!dq.empty() && dq.front() <= i-k) dq.pop_front();
        // current element is greater than previous, no need of previous in window
        while(!dq.empty() && arr[dq.back()] < arr[i]) dq.pop_back();
        // push current index
        dq.push_back(i);

        // window has started, so store window-max in result
        if(i >= k-1) res.push_back(arr[dq.front()]); // dq.front() stores the index of max in window
    }

    return res;
}

int main()
{
    vector<int> arr = {1,3,-1,-3,5,3,2,1,6};
    int k = 3;
    vector<int> res = windowMax(arr, k);
    cout<<"Max in window: ";
    for(auto i : res) cout<<i<<" ";
}