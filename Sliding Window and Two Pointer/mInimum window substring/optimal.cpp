#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    string minWindow(string s, string t) 
    {
        int n = s.length();

        if (t.length() > s.length())
            return "";

        // Step 1: Populate the frequency map for characters in t
        unordered_map<char, int> mp;
        for (auto &ch : t)
        {
            mp[ch]++;
        }

        // Step 2: Initialize required characters count
        int requiredCharactersIn_t = t.length();

        // Step 3: Sliding window variables
        int left = 0, right = 0, minWindowSize = INT_MAX;
        int startingIndex_of_substring_in_which_all_characters_of_t_are_present = 0;

        while (right < n)
        {
            char ch = s[right];

            // If the current character is needed
            if (mp[ch] > 0) 
            {
                requiredCharactersIn_t--;
            }

            // Reduce the frequency of the current character
            mp[ch]--;

            // Step 4: Shrink the window when all characters are found
            while (requiredCharactersIn_t == 0) 
            {
                int currentWindowSize = right - left + 1;
                if (minWindowSize > currentWindowSize)
                {
                    minWindowSize = currentWindowSize;
                    startingIndex_of_substring_in_which_all_characters_of_t_are_present = left;
                }

                // Increase the frequency of the left character since we are moving left
                mp[s[left]]++;
                if (mp[s[left]] > 0)
                {
                    requiredCharactersIn_t++;
                }

                left++;
            }

            right++;
        }

        return (minWindowSize == INT_MAX) ? "" : s.substr(startingIndex_of_substring_in_which_all_characters_of_t_are_present, minWindowSize);
    }
};

int main()
{
    string s;
    cout << "\nEnter the string s: ";
    cin >> s;

    string t;
    cout << "\nEnter the string t: ";
    cin >> t;

    Solution sol;
    cout << "\nThe minimum window substring is: " << sol.minWindow(s, t) << endl;

    return 0;
}
