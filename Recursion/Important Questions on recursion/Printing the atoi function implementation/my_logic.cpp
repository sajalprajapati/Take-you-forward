#include <bits/stdc++.h>
using namespace std;

unsigned long long int atoi_implementation(unsigned long long int number, const string &str, unsigned long long int index) {
    // Base case: if index reaches the end of the string, return the number
    if (index == str.length()) {
        return number;
    }
    // Recursive case: accumulate the number by shifting the previous digits left and adding the new digit
    return atoi_implementation(number * 10 + (str[index] - '0'), str, index + 1);
}

int main() {
    string str;
    cout << "\nEnter your string (numeric characters only): ";
    cin >> str;

    // Check for non-numeric characters
    for (char c : str) {
        if (!isdigit(c)) {
            cout << "\nInvalid input. The string should contain numeric characters only.\n";
            return 1;
        }
    }

    // Handle the case of an empty string
    if (str.empty()) {
        cout << "\nInvalid input. The string is empty.\n";
        return 1;
    }

    // Call the recursive function starting with 0 and index 0
    unsigned long long int result = atoi_implementation(0, str, 0);

    cout << "\nThe number is " << result << endl;
    return 0;
}
