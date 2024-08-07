#include <bits/stdc++.h>
using namespace std;

int sumOfMinimums(vector<int>& arr) {
    int n = arr.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int minimum = arr[i];
        sum += minimum;  // Sum of single-element subarrays
        for (int j = i + 1; j < n; j++) {
            minimum = min(minimum, arr[j]);
            sum += minimum;
        }
    }

    return sum;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    
    vector<int> arr(size);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int result = sumOfMinimums(arr);
    cout << "The sum of minimums of all subarrays is: " << result << endl;

    return 0;
}
