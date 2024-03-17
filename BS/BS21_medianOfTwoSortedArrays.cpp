#include <bits/stdc++.h>
using namespace std;

double median(vector<int> a, vector<int> b)
{
    int n1 = a.size();
    int n2 = b.size();

    int i=0, j=0;
    int n = n1+n2;

    // index of median in merged ... when n is even 2 ind are required, if odd 1 is required
    int ind2 = n/2;
    int ind1 = ind2 - 1;

    int ind1ele = -1, ind2ele = -1;

    int cnt = 0; // index tracker for merged

    // merge sort
    while(i < n1 && j < n2) // while inside array
    {
        if(a[i] < b[j])
        {
            if(cnt == ind1) ind1ele = a[i];
            if(cnt == ind2) ind2ele = a[i];
            i++;
            cnt++;
        }

        else
        {
            if(cnt == ind1) ind1ele = b[j];
            if(cnt == ind2) ind2ele = b[j];
            j++;
            cnt++;
        }
    }

    while(i < n1)
    {
        if(cnt == ind1) ind1ele = a[i];
        if(cnt == ind2) ind2ele = a[i];
        i++;
        cnt++;
    }

    while(j < n2)
    {
        if(cnt == ind1) ind1ele = b[j];
        if(cnt == ind2) ind2ele = b[j];
        j++;
        cnt++;
    }
    if(n%2==1) return ind2ele; // if odd
    return (ind1ele + ind2ele)/2; // if even
}

double medianBS(vector<int>& a, vector<int>& b)
{
    int n1 = a.size();
    int n2 = b.size();
    if(n2 > n1) median(b, a); // we swap a and b is b is greater as we apply BS on shorter array to reduce time complexity

    // left is the left part of merged array
    int left = (n1+n2+1)/2; // if n1+n2 = 3 left = 2, if n1+n2 = 4 left = 2
    int n = n1 + n2;

    int low=0, high=n1; // min 0 elements can be taken from a, max n1 can be taken
    while(low<=high)
    {
        int mid1 = (low + high) >> 1; // (low + high)/2 ... elements taken of a on left
        int mid2 = left - mid1; // elements of b on left are (total on left - elements of a on left)
        int l1 = INT_MIN, l2 = INT_MIN; // if noting on left
        int r1 = INT_MAX, r2 = INT_MAX; // if noting on right
        if(mid1<n1) r1 = a[mid1]; // if mid1 and n1 both are 6 then n1_index : [0 1 2 3 4 5], you cannot access index 6 (mid1)
        if(mid2<n2) r2 = b[mid2];
        if(mid1>=1) l1 = a[mid1-1]; // if mid1 is 0 ... a[-1] is invalid
        if(mid2>=1) l2 = b[mid2-1];

        if(l1<=r2 && l2<=r1)
        {
            if(n%2==1) return max(l1,l2); // if odd return median
            return (double)(max(l1,l2)+min(r1,r2))/2.0;
        }
        else if(l1>r2) high = mid1 - 1;
        else low = mid1 + 1; // if(l2>r1)
    }
    return 0;
}

int main()
{
    vector<int> a {1,3,4,7,10,13};
    vector<int> b {2,3,6,15};
    cout<<median(a,b)<<"\n"; // (4+6)/2 = 5

    a = {2,3,4};
    b = {1,3};
    cout<<median(a,b)<<"\n"; // 3

    a = {1,3,4,7,10,12};
    b = {2,3,6,15};
    cout<<medianBS(a,b);
    return 0;
}