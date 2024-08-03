#include <bits/stdc++.h>
using namespace std;

bool checking(int a) {
    int i;
    cout << "\nEnter the value of i: ";
    cin >> i;
    
    // Correct the condition using parentheses
    if ((a & (1 << i)) != 0)
        return true;
    else
        return false;
}

int main() {
    int a = 13;
    bool answer = checking(a);
    
    if (answer == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0;
}
