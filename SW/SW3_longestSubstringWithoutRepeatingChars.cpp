#include <bits/stdc++.h>
using namespace std;

// T: O(N^2)
// S: O(256)
int longestSubstringWithoutRepeatingChars(string str) {
    int n = str.size();
    int maxLen = 0;

    for(int i=0; i<n; i++) {
        vector<int> hash(256,0); // for 256 ASCII chars ... reset all to 0

        for(int j=i; j<n; j++) {
            if(hash[str[j]] == 1) break; // if char is repeated

            int len = j-i+1;
            maxLen = max(maxLen, len);
            hash[str[j]] = 1; // mark current char as visited, str[j] is a character, but it implicitly converts to its ASCII value (integer)
        }
    }

    return maxLen;
}

// T: O(N)
// S: O(256)
int longestSubstringWithoutRepeatingCharsOP(string str) {
    int n = str.size();
    int maxLen=0, l=0, r=0;
    vector<int> hash(256,-1); // stores index of each char

    while(r<n) {

        if(hash[str[r]] != -1) { // if already in map (hash)
            if(hash[str[r]] >= l) { // if this duplicate element comes after left pointer i.e. inside our window, then only update left pointer
                l = hash[str[r]]+1; // move left pointer to previous found element + 1
            }
        }

        maxLen = max(maxLen, r-l+1);
        hash[str[r]] = r;
        r++;
    }

    return maxLen;
}

int main()
{
    string str = "cadbzabcd";
    cout<<longestSubstringWithoutRepeatingChars(str)<<endl;

    cout<<longestSubstringWithoutRepeatingCharsOP(str)<<endl;
    return 0;
}