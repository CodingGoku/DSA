#include <bits/stdc++.h>
using namespace std;

// T: O(dividend)
// S: O(1)
int divide(int dividend, int divisor) {
    int sum=0, cnt=0;
    while(sum + divisor < dividend) {
        cnt++;
        sum += divisor;
    }

    return cnt;
}

// T: O(Log2 N)^2 ... for 2 nexted while loops
// S: O(1)
int divideOP(int dividend, int divisor) {
    if (dividend == divisor) return 1;
    
    if (dividend == INT_MIN && divisor == -1) return INT_MAX; // Prevent overflow

    bool sign = (dividend < 0) ^ (divisor < 0); // XOR for sign ... sign == true means negative result
    // WHY LONG LONG ?
    // abs(INT_MIN) causes an overflow because abs(-2^31) = 2^31, which is out of the range of int
    long long n = abs(1LL * dividend), d = abs(1LL * divisor); // Convert to long long
    int ans = 0;

    while (n >= d) {
        int cnt = 0;
        while (n >= (d << (cnt + 1))) { // d * 2^cnt+1
            cnt++;
        }

        ans += (1 << cnt); // 2^cnt
        n -= (d << cnt);
    }

    return sign ? -ans : ans;
}

int main() {
    int dividend = 22;
    int divisor = 3;
    cout << "Quotient: " << divide(dividend, divisor) << endl;
    cout << "Quotient: " << divideOP(dividend, divisor) << endl;
    return 0;
}
