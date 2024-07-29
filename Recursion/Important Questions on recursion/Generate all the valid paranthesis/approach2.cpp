#include <bits/stdc++.h>
using namespace std;

void generatingParanthesis(string current, vector<string> &answer, int n, int open, int close) {
    if (current.length() == 2 * n) {
        answer.push_back(current);
        return;
    }

    if (open < n) {
        current.push_back('(');
        generatingParanthesis(current, answer, n, open + 1, close);
        current.pop_back();
    }

    if (close < open) {
        current.push_back(')');
        generatingParanthesis(current, answer, n, open, close + 1);
        current.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    string current = "";
    vector<string> answer;
    generatingParanthesis(current, answer, n, 0, 0);
    return answer;
}

int main() {
    int number;
    cout << "Enter the number of generating valid parentheses: ";
    cin >> number;
    vector<string> answer = generateParenthesis(number);
    for (const auto &element : answer) {
        cout << "[" << element << "] ";
    }
    return 0;
}
