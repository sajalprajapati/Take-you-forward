#include <bits/stdc++.h>
using namespace std;

// This function checks whether one string is a rotation of another string
bool rotationCheck(const string &str1, const string &str2)
{
    if (str1.size() != str2.size()) return false; // Early return if sizes are different

    string temp = str1 + str1; // Concatenate str1 with itself

    // `find` returns the starting index of the first occurrence of str2 in temp
    // If str2 is not found, `find` returns string::npos
    if (temp.find(str2) != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
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

    bool allRotated = true; // Changed variable name for clarity
    for (int i = 0; i < n1; i++) {
        if (!rotationCheck(str1[i], str2[i])) {
            allRotated = false;
            break;
        }
    }

    if (allRotated) {
        cout << "\nThe strings are rotations of each other" << endl;
    } else {
        cout << "\nThe strings are not rotations of each other" << endl;
    }

    return 0;
}
