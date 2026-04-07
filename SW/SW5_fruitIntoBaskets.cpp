#include <bits/stdc++.h>
using namespace std;

// T : O(N x N)
// S : O(1)
int fruitIntoBaskets(vector<int>& arr) {
    int n = arr.size();
    int maxLen = 0;
    set<int> st; // to store the fruits 1,2,3 i.e. apple, orange, guava

    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            st.insert(arr[j]); // insert takes log(N), but here N is size of set which is 2 here, so we can neglect it

            if(st.size() <= 2) {
                maxLen = max(maxLen, j-i+1);
            }
            else {
                st.clear();
                break;
            }
        }
    }

    return maxLen;
}

// T : O(N + N) ... outer and inner while loop
// S : O(K) ... K elements in map
int fruitIntoBasketsOP(vector<int>& arr, int k) {
    int n = arr.size();
    int maxLen = 0;
    int l = 0, r = 0;
    unordered_map<int, int> mp; // num(Fruit), freq

    while(r < n) {
        mp[arr[r]]++;

        while(mp.size() > k) {
            mp[arr[l]]--;
            if(mp[arr[l]] == 0) mp.erase(arr[l]); // cannot store (num, 0) as it will give wrong size of map
            l++;
        }

        maxLen = max(maxLen, r-l+1);
        r++;
    }
    return maxLen;
}

// T : O(N) ... while loop
// S : O(K) ... K elements in map
int fruitIntoBasketsSOP(vector<int>& arr, int k) {
    int n = arr.size();
    int maxLen = 0;
    int l = 0, r = 0;
    unordered_map<int, int> mp; // num(Fruit), freq

    while(r < n) {
        mp[arr[r]]++;

        if(mp.size() > k) {
            mp[arr[l]]--;
            if(mp[arr[l]] == 0) mp.erase(arr[l]); // cannot store (num, 0) as it will give wrong size of map
            l++;
        }

        maxLen = max(maxLen, r-l+1);
        r++;
    }
    return maxLen;
}

int main()
{
    vector<int> arr = {3,3,3,1,2,1,1,2,3,3,4};

    cout<<fruitIntoBaskets(arr)<<endl;

    cout<<fruitIntoBasketsOP(arr, 2)<<endl;

    cout<<fruitIntoBasketsSOP(arr, 2)<<endl;
    return 0;
}