#include <bits/stdc++.h>
using namespace std;

// T: O(N)
// S: O(1)
bool jumpGame(vector<int>& jump) {
    int n = jump.size();

    int maxIndex = 0;
    for(int i=0; i<n; i++) {
        if(i > maxIndex) return false;

        maxIndex = max(maxIndex, i + jump[i]);
    }

    return true;
}

int main()
{
    vector<int> jump = {1,2,4,1,1,0,2,5};
    cout<<jumpGame(jump)<<endl;

    jump = {1,2,3,1,1,0,2,5};
    cout<<jumpGame(jump)<<endl;

    return 0;
}