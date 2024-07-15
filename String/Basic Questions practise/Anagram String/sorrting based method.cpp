#include <bits/stdc++.h>
using namespace std;

bool validAnagram(string s, string t)
{
    // If lengths of s and t are not the same, they cannot be anagrams
    if (s.length() != t.length()) return false;
    
    // Sort both strings
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    // Compare the sorted versions of the strings
    return s == t;
}

int main()
{
    string str1;
    string str2;
    cout << "\nEnter the first string: ";
    cin >> str1;
    cin.ignore();

    cout << "\nEnter the second string: ";
    cin >> str2;
    cin.ignore();

    if (str1.length() != str2.length()) {
        cout << "\nNot possible for the strings to be anagrams" << endl;
    } else {
        bool answer = validAnagram(str1, str2);
        if (answer) {
            cout << "\nThe strings are anagrams" << endl;
        } else {
            cout << "\nThe strings are not anagrams" << endl;
        }
    }

    return 0;
}
