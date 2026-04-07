#include <bits/stdc++.h>
using namespace std;

// T: O(1)
// S: O(1)
int xorFrom1toN(int n) {
    if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else if(n%4==3) return 0;
    else return n;
}

// T: O(1)
// S: O(1)
int xorInRange(int l, int r) {
    return xorFrom1toN(l-1) ^ xorFrom1toN(r);
}

int main()
{
    int l=4,r=7;
    cout<<"XOR from L to R: "<<xorInRange(l,r)<<endl;
    return 0;
}