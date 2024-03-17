#include <bits/stdc++.h>
using namespace std;

// Find the Nth root of M
int rt(int n, int m)
{
    int low=1, high=m;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(pow(mid,n) == m) return mid;

        if(pow(mid,n) > m) high = mid-1;
        else low = mid+1;
    }
    return -1;
}


int main()
{
    cout<<"3rd root of 64 : "<<rt(3,64)<<"\n";
    cout<<"4th root of 69 : "<<rt(4,69)<<"\n";
    return 0;
}