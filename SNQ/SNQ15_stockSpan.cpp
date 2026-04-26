#include <bits/stdc++.h>
using namespace std;

vector<int> findPGE(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> PGE(n);

    for(int i=0; i<n; i++) {
        while(!st.empty() && arr[st.top()] <= arr[i]) st.pop(); // we want greater that current in stack

        PGE[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return PGE;
}

// T: 2N ... to compute PGE
// S: N ... stack
vector<int> stockSpan(vector<int>& arr) {
    vector<int> PGE = findPGE(arr);

    vector<int> res(arr.size());
    for(int i=0; i<arr.size(); i++) {
        res[i] = i-PGE[i]; // length of stock span ... previous greatest to current
    }

    return res;
}

int main()
{
    vector<int> arr = {100,80,90,120};
    vector<int> res = stockSpan(arr);
    cout<<"Stock Span: ";
    for(auto i : res) cout<<i<<" ";
}