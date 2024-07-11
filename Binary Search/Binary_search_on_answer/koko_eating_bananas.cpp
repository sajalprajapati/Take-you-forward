#include <bits/stdc++.h>
using namespace std;

bool canEatAllTheBananas(vector<int> &piles, int middle, int hour) {
    int actualHour = 0;
    for (auto &x : piles) {
        actualHour += x / middle;
        if (x % middle != 0) {
            actualHour++;
        }
    }
    return actualHour <= hour;
}

int minEatingSpeed(vector<int> &v, int hour) {
    int lower = 1;
    int higher = *max_element(begin(v), end(v));

    while (lower <= higher) {
        int middle = lower + (higher - lower) / 2;

        if (canEatAllTheBananas(v, middle, hour)) {
            higher = middle - 1;
        } else {
            lower = middle + 1;
        }
    }

    return lower;
}

int main() {
    int size;
    vector<int> v;
    cout << "\nEnter the size of the piles of the bananas: " << endl;
    cin >> size;
    cout << "\nEnter the elements in the piles: " << endl;
    for (int i = 0; i < size; i++) {
        int element;
        cin >> element;
        v.push_back(element);
    }

    int hour;
    cout << "\nEnter the number of hours: " << endl;
    cin >> hour;

    int result = minEatingSpeed(v, hour);
    cout << "\nThe result is: " << result << endl;

    return 0;
}
