#include <bits/stdc++.h>
using namespace std;

// T: O(NlogN + N)
// S: O(1)
int shortestJobFirst(vector<int>& process) {
    int n = process.size();

    sort(begin(process), end(process));

    int currTime = 0, wtTime = 0;
    for(int i=0; i<n; i++) {
        wtTime += currTime;
        currTime += process[i];
    }

    return wtTime/n;
}

int main()
{
    vector<int> process = {4,3,7,1,2};
    cout<<shortestJobFirst(process)<<endl;

    return 0;
}