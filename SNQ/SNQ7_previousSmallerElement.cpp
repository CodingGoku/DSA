#include <bits/stdc++.h>
using namespace std;

// T : 2N ... while loop at max pops N elements, so it runs for N
// S : 2N
vector<int> previousSmaller(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n);

    for(int i=0; i<n; i++) {
        while(!st.empty() && st.top() >= nums[i]) st.pop();

        ans[i] = st.empty() ? -1 : st.top();

        // push current element to stack
        st.push(nums[i]);
    }

    return ans;
}

int main()
{
    vector<int> nums = {4,5,2,10,8};
    vector<int> ans = previousSmaller(nums);
    cout<<"previous smaller : ";
    for(auto i : ans) cout<<i<<" ";
    return 0;
}