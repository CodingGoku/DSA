#include <bits/stdc++.h>
using namespace std;

// T: O(N)
// S: O(1)
int singleNumber(vector<int>& arr) {
    int xorr = 0;
    for(auto i : arr) {
        xorr = xorr ^ i;
    }

    return xorr;
}

int main()
{
    vector<int> arr = {4,1,2,1,2};
    int xorr = singleNumber(arr);
    cout<<"number: "<<xorr<<endl;
    return 0;
}