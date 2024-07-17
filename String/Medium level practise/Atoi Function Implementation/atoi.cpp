#include <bits/stdc++.h>
using namespace std;

int atoi_function(string s) {
    if (s.size() == 0) return 0;

    int i = 0;
    while (i < s.size() && s[i] == ' ') {
        i++;
    }

    if (i == s.size()) return 0;

    int sign = +1;
    if (s[i] == '-' || s[i] == '+') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    int ans = 0;
    while (i < s.size() && isdigit(s[i])) {
        int digit = s[i] - '0';

        if (ans > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        ans = ans * 10 + digit;
        i++;
    }

    return ans * sign;
}

int main() {
    string number;
    cout << "Enter the string: ";
    getline(cin, number);

    int result = atoi_function(number);
    cout << "Converted integer: " << result << endl;

    return 0;
}
