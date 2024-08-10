class Solution {
  public:
    bool knows(vector<vector<int> >& mat, int a, int b) {
        return mat[a][b] == 1;
    }

    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        stack<int> stk;

        for (int i = 0; i < n; i++) {
            stk.push(i);
        }

        while (stk.size() > 1) {  // Corrected the condition here
            int A = stk.top();
            stk.pop();
            int B = stk.top();
            stk.pop();

            if (knows(mat, A, B))
                stk.push(B);
            else
                stk.push(A);
        }

        int candidate = stk.top();
        int zeroCount = 0;
        bool rowCheck = false;

        for (int i = 0; i < n; i++) {
            if (mat[candidate][i] == 0)
                zeroCount++;
        }

        if (zeroCount == n)
            rowCheck = true;

        int oneCount = 0;
        bool colCheck = false;

        for (int i = 0; i < n; i++) {
            if (mat[i][candidate] == 1)
                oneCount++;
        }

        if (oneCount == n - 1)
            colCheck = true;

        if (rowCheck && colCheck)
            return candidate;
        else
            return -1;
    }
};