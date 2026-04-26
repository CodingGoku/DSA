#include <bits/stdc++.h>
using namespace std;

// T : 4N ... while loop at max pops 2N elements, so it runs for 2N
// S : 4N
vector<int> nextGreater2(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n);

    for(int i=2*n-1; i>=0; i--) {
        while(!st.empty() && st.top() <= nums[i%n]) st.pop();

        if(i<n) {
            ans[i] = st.empty() ? -1 : st.top();
        }

        // push current element to stack
        st.push(nums[i%n]);
    }

    return ans;
}

int main()
{
    vector<int> nums = {2,10,12,1,11};
    vector<int> ans = nextGreater2(nums);
    cout<<"next greater : ";
    for(auto i : ans) cout<<i<<" ";
    return 0;
}
