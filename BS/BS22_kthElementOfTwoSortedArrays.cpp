#include <bits/stdc++.h>
using namespace std;

int kth(vector<int>& a, vector<int>& b, int k)
{
    int n1 = a.size();
    int n2 = b.size();
    int n = n1 + n2;

    if(n2 > n1) kth(b, a, k); // we swap a and b is b is greater as we apply BS on shorter array to reduce time complexity

    int left = k;
    int low = max(0, k-n2), high = min(k,n1); // min 0 taken from a, or k-n2 if k > n2 and max n1 taken on the left, not more than k

    int l1, l2;
    while(low<=high)
    {
        int mid1 = low + high >> 1; // of a on left
        int mid2 = left - mid1; // of b on left
        l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX; // if noting on right
        if(mid1<n1) r1 = a[mid1]; // if mid1 and n1 both are 6 then n1_index : [0 1 2 3 4 5], you cannot access index 6 (mid1)
        if(mid2<n2) r2 = b[mid2];
        if(mid1>=1) l1 = a[mid1-1]; // if mid1 is 0 ... a[-1] is invalid
        if(mid2>=1) l2 = b[mid2-1];

        if(l1<=r2 && l2<=r1)
        {
            return max(l1,l2); // return kth element
        }
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1; // if l2 > r1

    }
    return 0;
}
int main()
{
    vector<int> a {2,3,6,7,9};
    vector<int> b {1,4,8,10};
    int k  = 4;
    cout<<kth(a,b,k);
    return 0;
}