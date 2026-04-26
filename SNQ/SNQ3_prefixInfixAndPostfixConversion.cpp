#include <bits/stdc++.h>
using namespace std;

int priority(char ch) {
    if(ch=='^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='-' || ch=='+') return 1;
    else return -1; // for brackets ()
}

// T : O(N) + O(N) ... outer and inner while loop
// S : O(N) + O(N) ... satck and ans
string infixToPostfix(string s) {
    int i=0, n = s.size();
    stack<char> st;
    string ans = "";

    while(i<n) {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) ans = ans+s[i];
        else if(s[i] =='(') st.push(s[i]);
        else if(s[i]==')') {
            while(!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop(); // remove the opening bracket
        }
        else {
            while(!st.empty() && priority(s[i]) <= priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]); // can only push operator when priority(s[i]) > priority(st.top())
        }
        i++;
    }

    while(!st.empty()) {
        ans = ans + st.top();
        st.pop();
    }
    return ans;
}

// T : O(N/2) + O(N/2) + O(2N) ... for reverse, for end reverse, for stack iteration
// S : O(N) ... stack
string infixToPrefix(string s) {
    int n = s.size();
    reverse(s.begin(), s.end());
    // we need to reverse the brackets also
    for(int i=0; i<n; i++) {
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
    }
    int i=0;
    stack<char> st;
    string ans = "";

    while(i<n) {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) ans = ans+s[i];
        else if(s[i] == '(') st.push(s[i]);
        else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                ans = ans + st.top();
                st.pop();
            }
            st.pop(); // to pop (
        }
        else { // operator
            if(s[i] == '^') {
                while(!st.empty() && priority(s[i]) <= priority(st.top())) {
                    ans = ans + st.top();
                    st.pop();
                }
            }
            else {
                while(!st.empty() && priority(s[i]) < priority(st.top())) { // here is is not <=, but < only
                    ans += st.top();
                    st.pop();
                }
            }

            st.push(s[i]); // can only push operator when priority(s[i]) >= priority(st.top())
        }

        i++;
    }

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// T : O(N + N) ... for while loop, string concatination
// S : O(N) ... stack
string postfixToInfix(string s) {
    int n = s.size();
    stack<string> st;
    int i=0;

    while(i<n) {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) st.push(to_string(s[i]));
        else { // operator
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string conn = "("+t2+s[i]+t1+")"; // O(N1 + N2) ... concatination ... top2 then top1
            st.push(conn);
        }

        i++;
    }

    // now only 1 string should be in the stack, which should be the answer
    return st.top();
}

// T : O(N + N) ... for while loop, string concatination
// S : O(N) ... stack
string prefixToInfix(string s) {
    int n = s.size();
    stack<string> st;
    int i=n-1;

    while(i>=0) {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) st.push(to_string(s[i]));
        else { // operator
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string conn = "("+t1+s[i]+t2+")"; // O(N1 + N2) ... concatination ... top1 then top2
            st.push(conn);
        }

        i--;
    }

    // now only 1 string should be in the stack, which should be the answer
    return st.top();
}

// T : O(N + N) ... for while loop, string concatination
// S : O(N) ... stack
string postfixToprefix(string s) {
    int n = s.size();
    stack<string> st;
    int i=0;

    while(i<n) {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) st.push(to_string(s[i]));
        else { // operator
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string conn = "("+s[i]+t2+t1+")"; // O(N1 + N2) ... concatination ... op, then top2 then top1
            st.push(conn);
        }

        i++;
    }

    // now only 1 string should be in the stack, which should be the answer
    return st.top();
}

// T : O(N + N) ... for while loop, string concatination
// S : O(N) ... stack
string prefixToPostfix(string s) {
    int n = s.size();
    stack<string> st;
    int i=n-1;

    while(i>=0) {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) st.push(to_string(s[i]));
        else { // operator
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string conn = "("+t1+t2+s[i]+")"; // O(N1 + N2) ... concatination ... top1 then top2
            st.push(conn);
        }

        i--;
    }

    // now only 1 string should be in the stack, which should be the answer
    return st.top();
}

int main()
{
    return 0;
}