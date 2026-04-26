#include <bits/stdc++.h>
using namespace std;

// T: 3N + K
// S: 2N
string removeKdigits(string& str, int k) {
    int n = str.size();
    stack<char> st;

    for(int i=0; i<n; i++) {
        // found a larger digit it stack, pop it until <= str[i]
        while(!st.empty() && k>0 && st.top()-'0' > str[i]-'0') {
            st.pop();
            k--;
        }

        st.push(str[i]); // push to stack if str[i] >= st.top()
    }

    // if k remains in case of [1,2,3,4] as str[i] will be always >= st.top()
    // remove top k digits
    while(k) {
        st.pop();
        k--;
    }

    if(st.empty()) return "0";

    string res = "";
    while(!st.empty()) {
        res = res + st.top();
        st.pop();
    }

    // remove initial 0 digits like : "00123"
    // res will have 0s at the end because of stack
    while(res.size() != 0 && res.back() == '0') res.pop_back();

    // after removing zeroes, if res is empty, "000" if only contains 0s
    if(res.size() == 0) return  "0";

    // reverse res as stack gives reverse
    reverse(begin(res), end(res));

    return res;
}

int main()
{
    string str = "1432219";
    int k = 3;

    cout<<"After deleting K digits, smallest number: "<<removeKdigits(str, k);
}