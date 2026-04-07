#include <bits/stdc++.h>
using namespace std;

// T: O(log2 N) ... when you divide by 2 it gives log2 N
// S: O(log2 N) ... storing log2 N elements in res
string decimalToBinary(int n) {
    string res = "";
    while(n != 0) {
        res = to_string(n%2) + res;
        n = n/2;
    }

    return res;
}

// T: O(N)
// S: O(1)
int binaryToDecimal(string str) {
    int n = str.size();
    int sum = 0;
    int p2 = 1;
    for(int i=n-1; i>=0; i--) {
        if(str[i]=='1') {
            sum += p2;
        }
        p2 = p2*2; // for each binary power of 2 increases by multiple of 2
    }

    return sum;
}

int main()
{
    int n = 13;
    cout<<"Binary: "<<decimalToBinary(n)<<endl;
    
    string str = "1101";
    cout<<"Decimal: "<<binaryToDecimal(str)<<endl;
    return 0;
}