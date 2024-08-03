#include <bits/stdc++.h>
using namespace std;

int clearing(int &a) {
    int i;
    cout << "\nEnter the value of i: ";
    cin >> i;
    
    // Correct the condition using parentheses
    a=(a & ~(1<<i)) ;
    return a;
       
}

int main() {
    int a = 9;
    bool answer = clearing(a);
    
    cout<<a<<" "<<endl;
    
    return 0;
}
