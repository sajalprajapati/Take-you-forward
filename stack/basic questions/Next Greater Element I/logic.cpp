#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement_PART_I(vector<int> &v) {
    int n = v.size();
    vector<int> answer(n, -1); // Initialize answer vector with -1
    stack<int> stk;
   
    for (int i = n - 1; i >= 0; i--) {
        // Remove elements from the stack that are less than or equal to the current element
        while (!stk.empty() && stk.top() <= v[i]) {
            stk.pop();
        }
        
        // If the stack is not empty, the top element is the next greater element
        if (!stk.empty()) {
            answer[i] = stk.top();
        }

        // Push the current element onto the stack
        stk.push(v[i]); 
    }

    return answer;
}

int main() {
    vector<int> v;
    int size;
    cout << "\nEnter the size of the vector: " << endl;
    cin >> size;
    cout << "\nEnter the elements in the vector: " << endl;
    for (int i = 0; i < size; i++) {
        int element;
        cin >> element;
        v.push_back(element);
    }

    vector<int> answer = nextGreaterElement_PART_I(v);
    for (auto element : answer) {
        cout << element << " ";
    }
}
