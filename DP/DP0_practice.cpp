#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,k,x;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        cin>>n>>k>>x;
        vector<int> arr (n);
        int val=0;
        int ans = true;
        for(int j=0;j<n;j++)
        {
            if(val>x) {ans = false;break;}
            if(val==k) {val=x; if(x==k){val=x-1;}}
            arr[j] = val;
            if(val==x) continue;
            val++;
        }
        if(arr[n-1]<k-1) ans = false;
        if(ans) cout<<accumulate(arr.begin(),arr.end(),0)<<"\n";
        else cout<<-1<<"\n";
    }
    return 0;
}