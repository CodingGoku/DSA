#include <bits/stdc++.h>
using namespace std;

// T : 2N ... while loop at max pops N elements, so it runs for N
// S : 2N
vector<int> nextGreater(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n);

    for(int i=n-1; i>=0; i--) {
        // pop until we get the next greater element
        while(!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }

        if(!st.empty()) ans[i] = st.top();
        else ans[i] = -1; // if stack is empty

        // push current element
        st.push(nums[i]);
    }

    return ans;
}

int main()
{
    vector<int> nums = {4,12,5,3,1,2,5,3,1,2,4,6};
    vector<int> ans = nextGreater(nums);
    cout<<"next greater : ";
    for(auto i : ans) cout<<i<<" ";
    return 0;
}