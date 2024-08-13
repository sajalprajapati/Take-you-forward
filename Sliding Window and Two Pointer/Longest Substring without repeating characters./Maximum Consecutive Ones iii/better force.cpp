#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveOnes(vector<int> &v, int k) {
    int n = v.size();
    if (n == 1 || n == 0) return n;

    int left = 0, right = 0, zeroes = 0, maxLength = 0;

    while (right < n) {
        if (v[right] == 0) zeroes++; // Increment count of zeroes when a 0 is encountered

        // If number of zeroes exceeds k, move the left pointer to reduce zeroes count
        while (zeroes > k) {
            if (v[left] == 0) zeroes--;
            left++;
        }

        // Calculate the maximum length of the window
        int length = right - left + 1;
        maxLength = max(maxLength, length);

        right++;
    }

    return maxLength;
}

int main() {
    vector<int> v;
    int size;

    cout << "\nEnter the size of the vector: ";
    cin >> size;

    cout << "\nEnter the elements in the vector: ";
    for (int i = 0; i < size; i++) {
        int element;
        cin >> element;
        v.push_back(element);
    }

    int k = 2; // The maximum number of 0s you can flip to 1s
    cout << "\nThe longest maximum consecutive ones is: " << longestConsecutiveOnes(v, k) << endl;

    return 0;
}
