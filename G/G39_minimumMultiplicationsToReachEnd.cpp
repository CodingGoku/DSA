#include <bits/stdc++.h>
using namespace std;

#define mod 100000

// T : 100000 * N ... In the worst case, every element up to mod could be visited.
// Hence, the outer loop can run up to O(mod) times. For each element in the queue, we perform O(nums.size()) operations
// S : 100000 ... array of size mod, In the worst case, the queue can hold all possible values, up to O(mod)
int minimumMultiplications(vector<int>& nums, int start, int end) {
    vector<int> dist(1e5,1e9); // vector of size is 1e5 with value infinity ... as (values > 75 % mod) can give 75
    dist[start] = 0;

    queue<pair<int, int>> q; // steps, num
    q.push({0,start});

    while(!q.empty()) {
        int steps = q.front().first;
        int n = q.front().second;
        q.pop();

        for(int it : nums) {
            int val = (it*n)% mod;
            if(dist[val] > steps+1) { // don't write val <= end ... if val>end and (val*x)%mod = 75
                dist[val] = steps+1;
                if(val == end) return steps+1;
                q.push({steps+1,val});
            }
        }
    }

    return -1;
}

int main()
{
    int start = 3, end = 75;
    vector<int> nums = {2,5,7};
    cout<<"minimum multiplications : "<<minimumMultiplications(nums, start, end);
    return 0;
}