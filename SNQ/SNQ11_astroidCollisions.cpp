#include<bits/stdc++.h>
using namespace std;

vector<int> astroidCollisions(vector<int> arr) {
    int n = arr.size();
    stack<int> st;

    for(int i=0; i<n; i++) {
        if(arr[i] > 0) st.push(arr[i]);
        else {
            // keep popping (destroying) the smaller astroid in stack
            while(!st.empty() && st.top() > 0 && st.top() < abs(arr[i])) st.pop();
            // if both astroids are same, destroy both, as we destroy both this is not in while loop
            // so we dont go to next element in stack after popping
            if(!st.empty() && st.top() == abs(arr[i])) st.pop();

            // push negative astroids as they cannot collide
            else if(st.empty() || st.top() < 0) st.push(arr[i]);
        }
    }

    // store in vector the remaining astroids
    vector<int> res;
    while(!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }

    reverse(begin(res), end(res));
    return res;
}

int main() 
{
    vector<int> arr = {4,7,1,1,2,-3,-7,17,15,-18,-19};

    vector<int> res = astroidCollisions(arr);
    for(auto i : res) cout<<i<<" ";

    return 0;
}