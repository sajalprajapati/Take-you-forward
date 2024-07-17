#include <bits/stdc++.h>
using namespace std;

int calculation(const string& temp) {
    map<char, int> freq_map;
    for (char ch : temp) {
        freq_map[ch]++;
    }

    int min_freq = INT_MAX, max_freq = INT_MIN;
    for (const auto& entry : freq_map) {
        min_freq = min(min_freq, entry.second);
        max_freq = max(max_freq, entry.second);
    }

    return max_freq - min_freq;
}

int SumOfBeautyOfAllSubstrings(const string& s) {
    int answer = 0;
    for (size_t i = 0; i < s.size(); i++) {
        for (size_t j = i; j < s.size(); j++) {
            answer += calculation(s.substr(i, j - i + 1));
        }
    }
    return answer;
}

int main() {
    string s;
    cout << "\nPlease enter your string: " << endl;
    cin >> s;
    int count = SumOfBeautyOfAllSubstrings(s);
    cout << "\nThe sum of beauty of all substrings is: " << count << endl;
    return 0;
}
