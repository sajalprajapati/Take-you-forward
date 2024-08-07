class Solution {
public:
    const int MOD = 1e9 + 7;
    
    vector<int> getNSL(vector<int> &arr, int n) {
        vector<int> result(n);
        stack<int> stk;
        
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) stk.pop();
            
            result[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        
        return result;
    }

    vector<int> getNSR(vector<int> &arr, int n) {
        vector<int> result(n);
        stack<int> stk;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) stk.pop();
            
            result[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        
        return result;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);
        
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;
            
            long long totalWays = ls * rs;
            long long totalSum = arr[i] * totalWays;
            sum = (sum + totalSum) % MOD;
        }
        
        return sum;
    }
};
