#include <bits/stdc++.h>
using namespace std;

// T : N^2
// S : 1
int sumOfMin(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for(int i=0; i<n; i++) {
        int mini = nums[i];
        for(int j=i; j<n; j++) {
            mini = min(mini, nums[j]);
            sum += mini;
        }
    }
    return sum;
}

// Approach 2 : Using Next Smallest Element and Previous Smallest Element
#define MOD 1000000000

vector<int> findNSE(vector<int>& nums) {
    int n = nums.size();
    vector<int> nse(n);
    stack<int> st;

    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && nums[st.top()] >= nums[i]) st.pop(); // pop until we get next smaller

        nse[i] = st.empty() ? n : st.top(); // n if stack is empty
        st.push(i); // push current index in stack
    }

    return nse;
}

vector<int> findPSE(vector<int>& nums) {
    int n = nums.size();
    vector<int> pse(n);
    stack<int> st;

    for(int i=0; i<n; i++) {
        while(!st.empty() && nums[st.top()] > nums[i]) st.pop(); // pop until we get prev smaller or equal

        pse[i] = st.empty() ? -1 : st.top(); // -1 if stack is empty
        st.push(i); // push current index in stack
    }

    return pse;
}

// T : 5N
// S : 5N
long sum(vector<int>& nums) {
    int n = nums.size();
    long total = 0;

    vector<int> nse = findNSE(nums); // 2N
    vector<int> pse = findPSE(nums); // 2N

    for(int i=0; i<n; i++) {
        int left = i-pse[i];
        int right = nse[i]-i;
        total = (total+(right*left*1ll*nums[i])%MOD)%MOD;
    }

    return total;
}

int main()
{
    vector<int> nums = {3,1,2,4};
    cout<<"sum of subarray minimum : "<<sumOfMin(nums)<<"\n";
    vector<int> nums2 = {1,4,6,7,3,7,8,1};
    cout<<"sum of subarray minimum : "<<sum(nums2)<<"\n";
    return 0;
}