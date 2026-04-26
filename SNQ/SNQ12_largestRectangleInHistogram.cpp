#include<bits/stdc++.h>
using namespace std;

vector<int> findNSE(vector<int>& arr) {
    int n = arr.size();

    vector<int> nse(n);
    stack<int> st;
    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    return nse;
}

vector<int> findPSE(vector<int>& arr) {
    int n = arr.size();

    vector<int> pse(n);
    stack<int> st;
    for(int i=0; i<n; i++) {
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return pse;
}

// T: 5N ... 2 x (2N) for NSE and PSE, 1N for iteratiing 0-N to find largest rectangle at each index
// S: 4N ... 2 for vector, 2 for stack in NSE and PSE
int largestRectangle(vector<int>& arr) {
    int maxRect = 0;

    vector<int> NSE = findNSE(arr);
    vector<int> PSE = findPSE(arr);
    
    // try forming rectangle in each index
    for(int i=0; i<arr.size(); i++) {
        int length = NSE[i]-PSE[i]-1;
        int height = arr[i];
        maxRect = max(maxRect, length*height);
    }

    return maxRect;
}

// T : N + N ... for loop for push i, while loop to pop i
// S : N ... stack
int largestRectangleOP(vector<int>& arr) {
    int n = arr.size();
    int maxRect = 0;
    stack<int> st;

    for(int i=0; i<n; i++) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            int element = st.top();
            st.pop();

            // we are popping element as it is greater than arr[i]
            // so NSE of element is arr[i]
            int nse = i;
            int pse = st.empty() ? -1 : st.top(); // as stack only pushed element if found < arr[i]

            maxRect = max(maxRect, arr[element]*(nse-pse-1));
        }

        st.push(i); // it only pushes if st.top() < arr[i] ... so top gives PSE
    }

    // remaining in stack with no NSE
    // as we were popping only when we found NSE for that element
    while(!st.empty()) {
        int nse = n;
        int element = st.top();
        st.pop();

        int pse = st.empty() ? -1 : st.top();

        maxRect = max(maxRect, (nse-pse-1)*arr[element]);
    }

    return  maxRect;
}

int main()
{
    vector<int> arr = {2,1,5,6,2,3};
    cout<<"Largest Rectangle : "<<largestRectangle(arr)<<"\n";
    cout<<"Largest RectangleOP : "<<largestRectangleOP(arr);
}