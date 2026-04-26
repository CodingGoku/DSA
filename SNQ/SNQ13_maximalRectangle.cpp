#include <bits/stdc++.h>
using namespace std;

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

// T: (N X M) + (N X 2M) ... (N X M) for prefix + (N X 2M) for N times call to largestRectangle
// S: (N X M) + M ... for prefix + M for stack in largestHistogram
int maximalRectangle(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    // compute prefix sum for each column, current value tells the consecutive ones above it
    vector<vector<int>> prefix(n, vector<int>(m));

    for(int j=0; j<m; j++) {
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += mat[i][j];
            if(mat[i][j] == 0) sum = 0; // reset sum if zero is found
            prefix[i][j] = sum;
        }
    }

    // call largestRectangle for each row
    int maxi = 0;
    for(int i=0; i<n; i++) {
        maxi = max(maxi, largestRectangleOP(prefix[i]));
    }

    return maxi;
}

int main()
{
    vector<vector<int>> mat = {
        {1,0,1,0,1},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0}
    };

    cout<<"Maximal Rectangle: "<<maximalRectangle(mat);
}