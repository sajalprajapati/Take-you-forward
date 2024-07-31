#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &str, int idx, int i) {
    while (idx < i) {
        if (str[idx] != str[i]) {
            return false;
        }
        idx++;
        i--;
    }
    return true;
}

void backtrackingSolution(int idx, string &str, vector<string> &current, vector<vector<string>> &answer) {
    int n = str.length();

    if (idx == n) {
        answer.push_back(current);
        return;
    }

    for (int i = idx; i < n; i++) {
        if (isPalindrome(str, idx, i)) {
            current.push_back(str.substr(idx, i - idx + 1)); 
            backtrackingSolution(i + 1, str, current, answer);
            current.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> answer;
    vector<string> current;
    backtrackingSolution(0, s, current, answer);
    return answer;
}

int main() {
    string str;
    cout << "Enter your string: ";
    cin >> str;
    vector<vector<string>> answer = partition(str);

    for (auto &partition : answer) {
        for (auto &element : partition) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}
