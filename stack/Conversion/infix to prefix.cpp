#include <bits/stdc++.h>
using namespace std;

int priority(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return -1;
}

string infixToPrefix(string &s) {
    reverse(s.begin(), s.end());
    string answer = "";
    stack<char> stk;
    int n = s.length();
    int i = 0;

    while (i < n) {
        // Push operand directly to answer
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            answer = answer + s[i];
        }
        else if (s[i] == ')') {
            stk.push(s[i]);
        }
        else if (s[i] == '(') {
            while (!stk.empty() && stk.top() != ')') {
                answer = answer + stk.top();
                stk.pop();
            }
            if (!stk.empty()) stk.pop(); // Pop the ')'
        }
        else {
            // Process operator
            while (!stk.empty() && priority(s[i]) <= priority(stk.top())) {
                answer = answer + stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        }
        i++;
    }

    // Pop all remaining operators from the stack
    while (!stk.empty()) {
        answer = answer + stk.top();
        stk.pop();
    }

    // Reverse the answer to get the correct prefix expression
    reverse(answer.begin(), answer.end());

    return answer;
}

int main() {
    string s;
    cout << "\nEnter the string: ";
    cin >> s;
    cout << "\nThe prefix expression is: " << infixToPrefix(s) << endl;
    return 0;
}
