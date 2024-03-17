#include <bits/stdc++.h>
using namespace std;

int divSum(vector<int> arr, int div)
{
    int sum=0;
    for(int a : arr)
    {
        sum+=ceil((float)a/div);
    }
    return sum;
}

// T : O(log(max_element) x N)   ... as BS from 1->max_element and inside using divSum which is traversing the whole array
int divisor(vector<int> arr, int threshold)
{
    int low = 1, high = *max_element(arr.begin(),arr.end());

    while(low<=high)
    {
        int mid = low + (high - low)/2;
        // could be an answer
        if(divSum(arr,mid)<=threshold) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> arr {1,2,5,9};
    cout<<divisor(arr,6);
    return 0;
}