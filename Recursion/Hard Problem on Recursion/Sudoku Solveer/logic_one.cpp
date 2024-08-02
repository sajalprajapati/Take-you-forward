class Solution {
public:
bool validBox(vector<vector<char>>& board,int startingRow,int endingRow,int startingColumn,int endingColumn)
{
    unordered_set<char> st;
    for(int i=startingRow;i<=endingRow;i++)
    {
        for(int j=startingColumn;j<=endingColumn;j++)
        {
            if(board[i][j]=='.') continue;

            if(st.find(board[i][j])!=st.end())
            return false;

            st.insert(board[i][j]);
        }
    }

    return ture;
}
    void solveSudoku(vector<vector<char>>& board) 
    {
      //validating the row
      for(int i=0;i<=8;i++)
      {
        unordered_set<char> st;
        for(int j=0;j<=8;j++)
        {
         if(board[i][j]=='.') continue;

         if(st.find(board[i][j])!=st.end())
         return false;

         st.insert(board[i][j]);
        }

      
        //validating the column
      for(int j=0;j<=8;j++)
      {
        unordered_set<char> st;
        for(int i=0;i<=8;i++)
        {
         if(board[i][j]=='.') continue;

         if(st.find(board[i][j])!=st.end())
         return false;

         st.insert(board[i][j]);
        }
      }


      //validating 3*3 box;#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == ch) return false; // Check row
            if (board[i][col] == ch) return false; // Check column
            if (board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == ch) return false; // Check 3x3 sub-box
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, i, j, ch)) {
                            board[i][j] = ch;
                            if (solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution solution;
    solution.solveSudoku(board);

    for (const auto& row : board) {
        for (const auto& ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}

      for(int startingRow=0;i<9;i+3)
      {
        int endingRow=startingRow+2;
        for(int startingColumn=0;j<9;j+3)
        {
            int endingColumn=startingColumn+2;
            // if(board[i][j]=='.') continue;
              
            if(!validBox(board,startingRow,endingRow,startingColumn,endingColumn))
            return false;
        }
      }

      return true;    
    }
};