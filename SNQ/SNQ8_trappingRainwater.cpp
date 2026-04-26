#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Using LeftMax and RightMax
// T : 3N
// S : 2N
int rainwater(vector<int>& nums) {
    int n = nums.size();
    vector<int> leftmax(n), rightmax(n);
    
    int lmax=0;
    for(int i=0; i<n; i++) {
        lmax = max(lmax, nums[i]);
        leftmax[i] = lmax;
    }

    int rmax=0;
    for(int i=n-1; i>=0; i--) {
        rmax = max(rmax, nums[i]);
        rightmax[i] = rmax;
    }

    int total = 0;
    for(int i=0; i<n; i++) {
        if(nums[i] < leftmax[i] && nums[i] < rightmax[i]) {
            total += min(leftmax[i], rightmax[i]) - nums[i];
        }
    }

    return total;
}

// Approach 2 : prefixMax, SuffixMax
// T : 3N
// S : 2N
int rainwater2(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefixMax(n), suffixMax(n);

    prefixMax[0] = nums[0];
    for(int i=1; i<n; i++) prefixMax[i] = max(prefixMax[i-1], nums[i]);

    suffixMax[n-1] = nums[n-1];
    for(int i=n-2; i>=0; i--) suffixMax[i] = max(suffixMax[i+1], nums[i]);

    int total = 0;
    for(int i=0; i<n; i++) {
        if(nums[i] < prefixMax[i] && nums[i] < suffixMax[i]) {
            total += min(prefixMax[i], suffixMax[i]) - nums[i];
        }
    }

    return total;
}

// Approach 3 : 2 pointer
// T : N
// S : 1
int rainwater3(vector<int>& nums) {
    int n = nums.size();
    int lmax = 0, rmax = 0, total = 0;
    int l = 0, r = n-1;

    while(l<r) {
        // focus on smaller side (l/r) as smaller side is what is stored
        if(nums[l] <= nums[r]) { // when left value is smaller or equal
            if(lmax > nums[l]) total += lmax-nums[l];
            else lmax = nums[l]; // when nums[l] > lmax ... increase lmax

            l++;
        }
        else { // when right value is smaller
            if(rmax > nums[r]) total += rmax-nums[r];
            else rmax = nums[r]; // when nums[r] > rmax ... increase rmax

            r--;
        }
    }

    return total;
}

int main()
{
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<"trapped water : "<<rainwater(nums)<<"\n";
    cout<<"trapped water : "<<rainwater2(nums)<<"\n";
    cout<<"trapped water : "<<rainwater3(nums);
    return 0;
}