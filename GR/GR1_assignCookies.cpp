#include <bits/stdc++.h>
using namespace std;

// T: O(NlogN + MlogM + N)
// S: O(1)
int assignCookies(vector<int>& greed, vector<int>& cookies) {
    int n = greed.size();
    int m = cookies.size();

    sort(begin(greed), end(greed));
    sort(begin(cookies), end(cookies));

    int l = 0, r = 0;
    while(l<n && r<m) {
        if(greed[l] <= cookies[r]) {
            l++;
        }
        r++;
    }

    return l;
}

int main()
{
    vector<int> greed = {1,5,3,3,4};
    vector<int> cookies = {4,2,1,2,1,3};

    cout<<assignCookies(greed, cookies)<<endl;

    return 0;
}