#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<string> st;

    bool solve(int idx, string &s) {
        int n = s.length();
        
        // If we've reached the end of the string, return true
        if (idx >= n) {
            return true;
        }
        
        // Loop through possible lengths of substrings starting from idx
        for (int length = 1; idx + length <= n; ++length) {
            string temp = s.substr(idx, length);
            // If the substring is found in the set and the recursive call also returns true
            if (st.find(temp) != st.end() && solve(idx + length, s)) {
                return true;
            }
        }

        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        // Insert all words from wordDict into the set
        for (auto &word : wordDict) {
            st.insert(word);
        }
        
        return solve(0, s);
    }
};

int main() {
    Solution solution;
    
    // Test case
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    
    bool result = solution.wordBreak(s, wordDict);
    
    if (result) {
        cout << "The string \"" << s << "\" can be segmented into a space-separated sequence of one or more dictionary words." << endl;
    } else {
        cout << "The string \"" << s << "\" cannot be segmented into a space-separated sequence of one or more dictionary words." << endl;
    }

    return 0;
}
