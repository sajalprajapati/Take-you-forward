#include <bits/stdc++.h>
using namespace std;

string findCommonLongestElements(const vector<string> &elements) 
{
    string answer;
    
    // If elements is empty, return empty string
    if (elements.empty()) {
        return answer;
    }
    
    for (int i = 0; i < elements[0].length(); i++) {
        char ch = elements[0][i]; 

        // Boolean to check if the character 'ch' is present in all the strings at position 'i'
        bool match = true;
        for (int j = 1; j < elements.size(); j++) {
            if (elements[j].size() <= i || ch != elements[j][i]) {
                match = false;
                break;
            }
        }

        if (!match) {
            break;
        } else {
            answer.push_back(ch); // Add the matched character to the answer string
        }
    }

    return answer;   
}

int main() {
    vector<string> str;
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    cin.ignore(); // Ignore the newline character after the number

    cout << "Enter the strings:" << endl;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        str.push_back(s);
    }

    string commonElements = findCommonLongestElements(str);
    cout << "The common longest elements are: " << commonElements << endl;

    return 0;
}
