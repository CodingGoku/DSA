#include <bits/stdc++.h>
using namespace std;

// T : O(1) ... for each operation
// S : O(2N) ... for pair
class stk {
public:
    stack<pair<int, int>> st;
    int mini = INT_MAX;

    void push(int val) {
        if(st.empty()) {
            st.push({val,val});
        }

        else st.push({val, min(val, st.top().second)});
    }

    void pop() {
        st.pop();
    }

    int getMin() {
        return st.top().second;
    }
};



int main()
{
    stk s;
    s.push(3);
    s.push(2);
    s.push(4);
    cout<<"Min : "<<s.getMin();
    s.pop();
    cout<<"\npop";
    s.push(1);
    cout<<"\npush 1";
    cout<<"\nMin : "<<s.getMin();

    return 0;
}