#include <bits/stdc++.h>
using namespace std;

// 1. Swap 2 numbers without a third variable
void swap(int& a, int& b) {
    a = a ^ b;
    b = a ^ b; // = (a ^ b) ^ b = a ... now the value of b is a
    a = a ^ b; // = (a ^ b) ^ b ... as b is a ... (a ^ b) ^ a = b
}

// 2. Check if the ith bit is set or not
// T: O(1) ... computer performs bitwise operations much faster compared to other operations
// S: O(1)
bool isSet(int n, int i) {
    return (n & (1<<i)); // masking and taking AND ... anything positive returns true(1), else false(0)
}

// 3. Set the ith bit
int setBit(int n, int i) {
    return (n | (1<<i));
}

// 4. Clear the ith bit
int clearBit(int n, int i) {
    return (n & ~(1<<i));
}

// 5. Toggle the ith bit
int toggleBit(int n, int i) {
    return (n ^ (1<<i));
}

// 6. Remove the last set bit (rightmost)
int removeLastSetBit(int n) {
    return (n & (n-1));
}

// 7. Check if the number is a power of 2
bool isPowerOf2(int n) {
    if((n & n-1) == 0) return true;
    return false;
}

// 8. Count the number of Set bits
// T: O(log2 N) ... divide by 2
int countSetBits(int n) {
    int cnt=0;
    while(n != 0) {
        cnt += (n&1); // if(n % 2 == 1) cnt++;
        n = n >> 1; //n = n/2; 
    }
    return cnt;
}

// T: O(number of set bits)
int countSetBits2(int n) {
    int cnt = 0;
    while(n != 0) {
        n = n & (n-1); // removes rightmost set bit
        cnt++;
    }
    return cnt;
}

int main()
{
    int a = 2;
    int b = 4;
    swap(a,b);
    cout<<"after swap -> a: "<<a<<" b: "<<b<<endl;

    int n = 13;
    int i = 2;
    cout<<"isSet: "<<isSet(n,i)<<endl;

    n = 9;
    i = 2;
    cout<<"setBit: "<<setBit(n,i)<<endl;

    n = 13;
    i = 2;
    cout<<"clearBit: "<<clearBit(n,i)<<endl;

    n = 13;
    i = 1;
    cout<<"toggleBit: "<<toggleBit(n,i)<<endl;

    n = 12;
    cout<<"removeLastSetBit: "<<removeLastSetBit(n)<<endl;

    n = 16;
    cout<<"isPowerOf2: "<<isPowerOf2(n)<<endl;

    n = 13;
    cout<<"countSetBits: "<<countSetBits(n)<<endl;

    cout<<"countSetBits2: "<<countSetBits2(n)<<endl;

    return 0;
}