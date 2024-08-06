#include <bits/stdc++.h>
using namespace std;

vector<int> NextGreaterElement_partII(vector<int>& v) {
    if (v.size() == 0 || v.size() == 1)
        return v;

    int n = v.size();
    stack<int> stk;
    vector<int> answer(v.size(), -1);

    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!stk.empty() && stk.top() <= v[i % n]) {
            stk.pop();
        }

        if (i < n) {
            if (!stk.empty()) answer[i] = stk.top();
        }

        stk.push(v[i % n]);
    }

    return answer;
}

int main() {
    vector<int> v;
    int size;
    cout << "Enter the size of the vector: ";
    cin >> size;
    cout << "Enter the elements in the vector:" << endl;
    for (int i = 0; i < size; i++) {
        int element;
        cin >> element;
        v.push_back(element);
    }

    vector<int> answer = NextGreaterElement_partII(v);

    cout << "The next greater elements are: ";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}
