#include <bits/stdc++.h>
using namespace std;

bool checker(vector<int> &boards, int middle, int k) {
    int kth = 1;
    int totaltimeForpainter = 0;

    for (int i = 0; i < boards.size(); i++) {
        if (totaltimeForpainter + boards[i] <= middle) {
            totaltimeForpainter += boards[i];
        } else {
            kth++;
            if (kth > k) {
                return false;
            }
            totaltimeForpainter = boards[i]; // Start new painter with current board
        }
    }

    return true;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    sort(boards.begin(), boards.end());

    int lower = *max_element(boards.begin(), boards.end());
    int higher = accumulate(boards.begin(), boards.end(), 0); // Total sum of board lengths
    int answer = higher;

    while (lower <= higher) {
        int middle = lower + (higher - lower) / 2;

        if (checker(boards, middle, k)) {
            answer = middle;
            higher = middle - 1; // Try for a smaller maximum time
        } else {
            lower = middle + 1; // Increase the maximum time
        }
    }

    return answer;
}

int main() {
    int n;
    cout << "Enter the number of boards: ";
    cin >> n;

    vector<int> boards(n);
    cout << "Enter the length of each board:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> boards[i];
    }

    int k;
    cout << "Enter the number of painters: ";
    cin >> k;

    if (k > n) {
        cout << "Number of painters cannot be greater than the number of boards." << endl;
        return 1;
    }

    int result = findLargestMinDistance(boards, k);
    cout << "The largest minimum time required is: " << result << endl;

    return 0;
}
