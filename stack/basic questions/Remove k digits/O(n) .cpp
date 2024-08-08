class Solution {
public:
    string removeKdigits(string num, int k) {
        string answer = "";  // This will store the resulting number
        
        for (int i = 0; i < num.length(); i++) {
            // Remove the last character of answer while it is larger than the current num[i]
            // and we still have digits to remove (k > 0)
            while (answer.length() > 0 && answer.back() > num[i] && k > 0) {
                answer.pop_back();
                k--;
            }

            // Append the current character to answer if it's not a leading zero
            if (answer.length() > 0 || num[i] != '0') {
                answer.push_back(num[i]);
            }
        }

        // If we still have digits to remove, remove them from the end
        while (k > 0 && answer.length() > 0) {
            answer.pop_back();
            k--;
        }

        // If answer is empty after removing all digits, return "0"
        if (answer.empty()) {
            return "0";
        }

        return answer;
    }
};
