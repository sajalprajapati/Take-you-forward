#include <bits/stdc++.h>
using namespace std;

bool isomorphicString(const string &s, const string &t) 
{
   if (s.size() != t.size()) return false; // Early return if sizes are different
   
   unordered_map<char, char> mp1;
   unordered_map<char, char> mp2;

   int n = s.size();

   for (int i = 0; i < n; i++)
   {
       char ch1 = s[i];
       char ch2 = t[i];

       if ((mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2) || 
           (mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1))
       {
           return false;
       }
       mp1[ch1] = ch2;
       mp2[ch2] = ch1;
   }

   return true;
}

int main() {
    vector<string> str1;
    int n1;
    cout << "Enter the number of strings for str1: ";
    cin >> n1;
    cin.ignore(); // Ignore the newline character after the number

    cout << "Enter the strings for str1:" << endl;
    for (int i = 0; i < n1; i++) {
        string s;
        getline(cin, s);
        str1.push_back(s);
    }

    vector<string> str2;
    int n2;
    cout << "Enter the number of strings for str2: ";
    cin >> n2;
    cin.ignore(); // Ignore the newline character after the number

    cout << "Enter the strings for str2:" << endl;
    for (int i = 0; i < n2; i++) {
        string s;
        getline(cin, s);
        str2.push_back(s);
    }

    if (n1 != n2) {
        cout << "\nThe number of strings in str1 and str2 should be equal for pairwise comparison." << endl;
        return 0;
    }

    bool allIsomorphic = true;
    for (int i = 0; i < n1; i++) {
        if (!isomorphicString(str1[i], str2[i])) {
            allIsomorphic = false;
            break;
        }
    }

    if (allIsomorphic) {
        cout << "\nThe strings are isomorphic" << endl;
    } else {
        cout << "\nThe strings are not isomorphic" << endl;
    }

    return 0;
}
