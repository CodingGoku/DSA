#include <bits/stdc++.h>
using namespace std;

// T : O(N)
// S : O(N)
bool isBalanced(string str) {
    stack<char> st;

    for(auto ch : str) {
        // opening bracket
        if(ch == '(' || ch == '[' || ch == '{') st.push(ch);
        // closing bracket
        else {
            if(st.empty()) return false; // if it is empty and we get a closing bracket, then it is not valid
                
            if((ch == ')' && st.top() == '(') || (ch == ']' && st.top() == '[') || (ch == '}' && st.top() == '{')) st.pop();
            else return false;
        }
    }
    
    // stack should be empty for it to be valid, in the end we can't have some opening brackets in stack
    if(st.empty()) return true;
    return false;
}

int main()
{
    string str = "()[{}()]";
    cout<<isBalanced(str)<<"\n";
    str = "()[{}(])";
    cout<<isBalanced(str)<<"\n";
    return 0;
}