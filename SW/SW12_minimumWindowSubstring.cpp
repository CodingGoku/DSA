#include <bits/stdc++.h>
using namespace std;

// T: O(N^2)
// S: O(N)
string minimumWindowString(string str, string target) {
    int n = str.size();
    int m = target.size();
    int minLen = INT_MAX, startIndex = 0;
    unordered_map<char, int> freq;

    int cnt = 0; // stores count of chars found in str from target
    for(int i=0; i<n; i++) {

        freq.clear();
        int cnt = 0;
        // store target chars
        for(auto it : target) freq[it]++;

        for(int j=i; j<n; j++) {
            if(freq[str[j]] > 0) cnt++; // found a char from target in str
            freq[str[j]]--;

            if(cnt == m) { // found all chars from target
                if((j-i+1) < minLen) {
                    minLen = j-i+1;
                    startIndex = i;
                    break;
                }
            }
        }
    }

    return str.substr(startIndex, minLen);
}

// T: O(2N + M)
// S: O(N)
string minimumWindowStringOP(string str, string target) {
    int n = str.size();
    int m = target.size();
    int l = 0, r = 0;
    int minLen = INT_MAX, startIndex = -1;
    unordered_map<char, int> freq; // stores chars needed to get target

    for(int i=0; i<m; i++) freq[target[i]]++;

    int cnt = 0;
    while(r < n) {
        if(freq[str[r]] > 0) cnt++;
        freq[str[r]]--;

        while(cnt == m) {
            if(r-l+1 < minLen) {
                minLen = r-l+1;
                startIndex = l;
            }

            // move l by 1
            freq[str[l]]++; // freq will increase as it is not in out window anymore
            if(freq[str[l]] > 0) cnt--; // if this char was in target, count will decrease as now that char is not in window
            l++;
        }

        r++;
    }

    return startIndex == -1 ? "" : str.substr(startIndex, minLen);
}

int main()
{
    string str = "ddaaabbca";
    string target = "abc";

    cout<<minimumWindowString(str, target)<<endl;

    cout<<minimumWindowStringOP(str, target)<<endl;

    return 0;
}