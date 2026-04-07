#include <bits/stdc++.h>
using namespace std;

// T: O(N^N)
// S: O(N) ... stack space
int jumpGame2(vector<int>& jump, int index, int jumps) {
    if(index >= jump.size()-1) return jumps;
    int mini = INT_MAX;
    for(int i=1; i<=jump[index]; i++) { // starting from 1 and not 0 as we dont want to jump to the same position
        mini = min(mini, jumpGame2(jump, index+i, jumps+1)); // index + i, so jump will be like curr+1, curr+2, curr+3, ...
    }
    return mini;
}

// T: O(N^2)
// S: O(N^2)
int jumpGame2OP(vector<int>& jump, int index, int jumps, vector<vector<int>>& dp) {
    if(index >= jump.size()-1) return jumps;
    if(dp[index][jumps] != -1) return dp[index][jumps];

    int mini = INT_MAX;
    for(int i=1; i<=jump[index]; i++) {
        mini = min(mini, jumpGame2OP(jump, index+i, jumps+1, dp));
    }
    return dp[index][jumps] = mini;
}

// T: O(N)
// S: O(1)
int jumpGame2SOP(vector<int>& jump) {
    int jumps = 0;
    int l=0, r=0;
    int n = jump.size();

    while(r < n-1) {
        int farthest = 0;
        for(int i=l; i<=r; i++) {
            farthest = max(farthest, i+jump[i]);
        }

        l = r+1;
        r = farthest;
        jumps++;
    }

    return jumps;
}

int main()
{
    vector<int> jump = {2,3,1,1,4};
    cout<<jumpGame2(jump, 0, 0)<<endl;

    int n = jump.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
    cout<<jumpGame2OP(jump, 0, 0, dp)<<endl;

    cout<<jumpGame2SOP(jump)<<endl;
    return 0;
}