#include <bits/stdc++.h>
using namespace std;

string reversalOfTheString(string s) {
    stack<string> st; // Stack to store words
    string ss = ""; // Temporary string to build each word
    int i = 0;
    int sizeOfString = s.size();
    
    while (i < sizeOfString) {
        if (s[i] != ' ') {
            ss += s[i];
        } else if (!ss.empty()) {
            st.push(ss);
            ss.clear();
        }
        i++;
    }
    
    if (!ss.empty()) { // Push the last word if there's any left
        st.push(ss);
    }

    string ans = ""; // This will store our final answer
    while (!st.empty()) {
        ans += st.top();
        st.pop();
        if (!st.empty()) {
            ans += ' ';
        }
    }

    return ans;
}

int main() {
    string s;
    cout << "Enter your string: " << endl;
    getline(cin, s);
    string result = reversalOfTheString(s);
    cout << "The string after reversing the words is: " << result << endl;
    return 0;
}
