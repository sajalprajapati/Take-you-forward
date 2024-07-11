#include <bits/stdc++.h>
using namespace std;

// Function to calculate middle^n and check against m
int raised_function(int middle, int n, int m) {
    long long ans = 1;
    
    for (int i = 1; i <= n; i++) {
        ans = ans * middle;
        
        // If ans becomes greater than m, return 2
        if (ans > m) {
            return 2;
        }
    }
    
    if (ans == m) {
        return 1; // Exact match
    } else {
        return 0; // ans < m
    }
}

// Binary search to find the integer x such that x^n = m
int binary_search_root(int n, int m) {
    int lower = 1;
    int upper = m;
    
    while (lower <= upper) {
        int middle = lower + (upper - lower) / 2;
        
        int result = raised_function(middle, n, m);
        
        if (result == 1) {
            return middle; // Found the exact root
        } else if (result == 0) {
            lower = middle + 1; // Try higher values
        } else {
            upper = middle - 1; // Try lower values
        }
    }
    
    return -1; // If no such integer exists
}

int main() {
    int n, m;
    cout << "Enter the value of n (exponent): ";
    cin >> n;
    cout << "Enter the value of m (number to find the n-th root of): ";
    cin >> m;
    
    int root = binary_search_root(n, m);
    if (root == -1) {
        cout << "The required root of the number is not possible." << endl;
    } else {
        cout << "The required root of the number is " << root << "." << endl;
    }
    
    return 0;
}
