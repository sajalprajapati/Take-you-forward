#include <bits/stdc++.h>
using namespace std;

string odd_integer(string s) {
    int sizeOfArray = s.size();
    int ans = INT_MIN;

    for (int i = 0; i < sizeOfArray; i++) {
        char digitChar_i = s[i];
        int digitValue_i = digitChar_i - '0';
        
        if (digitValue_i % 2 == 1) {
            ans = max(ans, digitValue_i);
        }

        for (int j = i + 1; j < sizeOfArray; j++) {
            char digitChar_j = s[j];
            int digitValue_j = digitChar_j - '0';

            digitValue_i = digitValue_i * 10 + digitValue_j;

            if (digitValue_i % 2 == 1) {
                ans = max(ans, digitValue_i);
            }
        }
    }

    if (ans == INT_MIN) {
        return "No odd number found";
    }

    return to_string(ans);
}

int main() {
    string s;
    cout << "\nEnter the number: ";
    cin >> s;

    cout << "\nThe largest odd integer is: " << odd_integer(s) << endl;
}
