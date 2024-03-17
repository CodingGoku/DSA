#include <bits/stdc++.h>
using namespace std;

// brute force
int square(int k)
{
    int ans=1;
    for(int i=1;i<k;i++)
    {
        if(i*i<=k) ans=i;
        else break;
    }
    return ans;
}

int sqrt2(int k)
{
    int low = 1, high = k;
    int ans=0; // for when k is 0
    while(low<=high)
    {
        long mid = low + (high-low)/2; // long bcoz mid*mid is > INT_MAX
        // can be a possible ans
        if(mid*mid <= k)
        {
            ans=mid;
            low = mid + 1; // find max value mid^2 <= k  ... so eliminate left part with smaller values
        }
        else high = mid - 1;

    }
    return ans;
}

int main()
{
    cout<<square(64)<<"\n";
    cout<<sqrt2(37);
    return 0;
}