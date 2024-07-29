#include <bits/stdc++.h>
using namespace std;

// Function to insert element at the bottom of the stack
void reversingFunction(stack<int> &s, int element) {
    if (s.empty()) {
        s.push(element);
        return;
    }

    int a = s.top();
    s.pop();
    reversingFunction(s, element);
    s.push(a);
}

// Function to reverse the stack using recursion
void reversing(stack<int> &s) {
    if (s.empty())
        return;

    int temp = s.top();
    s.pop();
    reversing(s);
    reversingFunction(s, temp);
}

int main() {
    stack<int> s;
    cout << "Enter the elements in the stack (end input with a non-integer): ";
    int element;

    // Take input until a non-integer is entered
    while (cin >> element) {
        s.push(element);
    }

    cin.clear(); // Clear the error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any remaining input

    // Reverse the stack
    reversing(s);

    // Print the reversed stack
    cout << "Reversed stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
