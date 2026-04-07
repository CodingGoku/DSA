#include <bits/stdc++.h>
using namespace std;

// T : varies from example to example
// S : N
vector<vector<string>> wordLadder(vector<string>& wordList, string startWord, string targetWord) {
    int n = startWord.size();
    if(n != targetWord.size()) return {}; // not possible

    queue<vector<string>> q;
    q.push({startWord}); // initially start with startWord
    unordered_set<string> st(wordList.begin(), wordList.end());
    vector<string> usedOnLevel;
    usedOnLevel.push_back(startWord); //used on level=0
    int level=0;

    vector<vector<string>> result;
    while(!q.empty()) {
        vector<string> vec = q.front();
        q.pop();

        // erase all words that have been
        // used in the previous levels to transform
        if(vec.size() > level) { //we are on next level
            level++;
            for(auto it : usedOnLevel) {
                st.erase(it);
            }
            usedOnLevel.clear(); // as they have been deleted from set, we can clear from usedOnLevel
        }

        string word = vec.back(); // last word in vector

        // reached targetWord
        if(word == targetWord) {
            if(result.size() == 0) {
                result.push_back(vec);
            }
            else if(result[0].size() == vec.size()) { // as we want only shortest answers only ... multiple solutions
                result.push_back(vec); // of same length
            }
        }

        for(int i=0; i<n; i++) {
            char original = word[i];
            for(char ch='a'; ch<='z'; ch++) {
                word[i] = ch; // replace ith char
                if(st.find(word) != st.end()) {
                    vec.push_back(word);
                    q.push(vec);
                    // mark as visited on the level
                    usedOnLevel.push_back(word);
                    vec.pop_back(); // pop last word to try another word on this level
                }
            }
            word[i] = original; // so that we replace only 1 char at a time
        }
    }
    return result;
}

int main()
{
    vector<string> wordList = {"pat","bot","pot","poz","coz"};
    string startWord = "bat";
    string targetWord = "coz";
    vector<vector<string>> s = wordLadder(wordList, startWord, targetWord);
    for(auto it : s) {
        cout<<"[";
        for(auto i : it) {
            cout<<i<<" ";
        }
        cout<<"]\n";
    }
    return 0;
}