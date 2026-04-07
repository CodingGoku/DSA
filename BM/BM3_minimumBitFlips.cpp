#include <bits/stdc++.h>
using namespace std;

int minimumBitFlips(int start, int goal) {
    int xorr = start ^ goal; // opposite bits give 1, same bits give 0

    // xor's binary has the bits that we need to flip in the form of set bits

    // count set bits in xor
    int cnt = 0;
    while(xorr != 0) {
        xorr = xorr & (xorr-1); // removes rightmost set bit
        cnt++;
    }

    return cnt;
}

int main()
{
    int start = 10;
    int goal = 7;
    cout<<"Minimum Bit Flips: "<<minimumBitFlips(start, goal)<<endl;

    return 0;
}