#include <bits/stdc++.h>
using namespace std;

// T: O(N^2)
// S: O(26)
int longestRepeatingCharReplacement(string str, int k) {
    int n = str.size();
    int maxLen = 0;
    unordered_map<char, int> freq;

    for(int i=0; i<n; i++) {
        freq.clear();
        int maxFreq = 0;
        int changes = 0;
        for(int j=i; j<n; j++) {
            freq[str[j]]++;
            maxFreq = max(maxFreq, freq[str[j]]);

            changes = (j-i+1) - maxFreq; // changes = total - element with maxFreq
            if(changes <= k) maxLen = max(maxLen, j-i+1);
            else break;
        }
    }

    return maxLen;
}

// T: O((N + N) x 26) ... outer loop, inner loop, maxFreq check
// S: O(26)
int longestRepeatingCharReplacementOP(string str, int k) {
    int n = str.size();
    int maxLen = 0;
    int l = 0, r = 0;
    unordered_map<int, int> freq;
    int maxFreq = 0;

    while(r < n) {
        freq[str[r] - 'A']++;
        maxFreq = max(maxFreq, freq[str[r] - 'A']);

        while(r-l+1 - maxFreq > k) { // to replace = total - element with max freq
            freq[str[l] - 'A']--;
            maxFreq = 0; // max freq gets changed after sliding window, so we'll update it
            for(int i=0; i<26; i++) {
                maxFreq = max(maxFreq, freq[i]);
            }

            l++;
        }

        maxLen = max(maxLen, r-l+1);
        r++;
    }

    return maxLen;
}

// T: O(N) ... loop
// S: O(26)
int longestRepeatingCharReplacementSOP(string str, int k) {
    int n = str.size();
    int maxLen = 0;
    int l = 0, r = 0;
    unordered_map<int, int> freq;
    int maxFreq = 0;

    while(r < n) {
        freq[str[r] - 'A']++;
        maxFreq = max(maxFreq, freq[str[r] - 'A']);

        if(r-l+1 - maxFreq > k) { // to replace = total - element with max freq
            freq[str[l] - 'A']--;
            // maxFreq = 0; // max freq gets changed after sliding window, so we'll update it
            // for(int i=0; i<26; i++) {
            //     maxFreq = max(maxFreq, freq[i]);
            // }

            l++;
        }

        maxLen = max(maxLen, r-l+1);
        r++;
    }

    return maxLen;
}

int main()
{
    string str = "AABABBA";
    int k = 2;

    cout<<longestRepeatingCharReplacement(str, k)<<endl;
    cout<<longestRepeatingCharReplacementOP(str, k)<<endl;
    cout<<longestRepeatingCharReplacementSOP(str, k)<<endl;

    return 0;
}