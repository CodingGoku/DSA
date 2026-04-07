#include <bits/stdc++.h>
using namespace std;

// T: O(N^2 x Log(256)) ... assuming map takes log time
// S: O(256)
int longestSubstringWithAtMostKdistinctChars(vector<char>& arr, int k) {
    int n = arr.size();
    int maxLen=0;
    unordered_map<char, int> freq;

    for(int i=0; i<n; i++) {
        freq.clear();
        for(int j=i; j<n; j++) {
            freq[arr[j]]++;
            if(freq.size() <= k) maxLen = max(maxLen, j-i+1);
            else break;
        }
    }
    return maxLen;
}

// T: O(N + N + log 256) ... for l, r, map
// S: O(256)
int longestSubstringWithAtMostKdistinctCharsOP(vector<char>& arr, int k) {
    int n = arr.size();
    int maxLen = 0;
    unordered_map<char, int> freq;
    int l = 0, r = 0;

    while(r < n) {
        freq[arr[r]]++;
        while(freq.size() > k) {
            freq[arr[l]]--;
            if(freq[arr[l]] == 0) freq.erase(arr[l]);  // cannot store (char, 0) as it will give wrong size of map
            l++;
        }
        maxLen = max(maxLen, r-l+1);

        r++;
    }

    return maxLen;
}

// T: O(N + log 256) ... for r, map
// S: O(256)
int longestSubstringWithAtMostKdistinctCharsSOP(vector<char>& arr, int k) {
    int n = arr.size();
    int maxLen = 0;
    unordered_map<char, int> freq;
    int l = 0, r = 0;

    while(r < n) {
        freq[arr[r]]++;
        if(freq.size() > k) {
            freq[arr[l]]--;
            if(freq[arr[l]] == 0) freq.erase(arr[l]);  // cannot store (char, 0) as it will give wrong size of map
            l++;
        }
        maxLen = max(maxLen, r-l+1);

        r++;
    }

    return maxLen;
}

int main()
{
    vector<char> arr = {'a','a','a','b','b','c','c','d'};
    int k = 2;

    cout<<longestSubstringWithAtMostKdistinctChars(arr, k)<<endl;
    cout<<longestSubstringWithAtMostKdistinctCharsOP(arr, k)<<endl;
    cout<<longestSubstringWithAtMostKdistinctCharsSOP(arr, k)<<endl;

    return 0;
}