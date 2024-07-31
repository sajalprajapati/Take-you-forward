//i don't have to use chatgpt to correct my code.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solutionFunction(int row, int column, string &temp, vector<vector<int>> &matrix, vector<string> &answer) {
        int n = matrix.size();

        if (row < 0 || row >= n || column < 0 || column >= n || matrix[row][column] != 1) {
            return;
        }

        if (row == n - 1 && column == n - 1) {
            answer.push_back(temp);
            return;
        }

        matrix[row][column] = 0; // Mark the cell as visited

        // Exploring left part
        temp.push_back('L');
        solutionFunction(row, column - 1, temp, matrix, answer);
        temp.pop_back();

        // Exploring right part
        temp.push_back('R');
        solutionFunction(row, column + 1, temp, matrix, answer);
        temp.pop_back();

        // Exploring bottom part
        temp.push_back('D');
        solutionFunction(row + 1, column, temp, matrix, answer);
        temp.pop_back();

        // Exploring top part
        temp.push_back('U');
        solutionFunction(row - 1, column, temp, matrix, answer);
        temp.pop_back();

        matrix[row][column] = 1; // Unmark the cell
    }

    vector<string> findPath(vector<vector<int>> &maze) {
        vector<string> answer;
        if (maze.empty() || maze[0].empty() || maze[0][0] == 0 || maze[maze.size() - 1][maze[0].size() - 1] == 0) {
            return answer; // Return empty if start or end is blocked
        }
        string temp = "";
        solutionFunction(0, 0, temp, maze, answer);
        return answer;
    }
};


int main()
{
    int t;
    cout<<"Enter the value of t";
    cin>>t;
    while(t--)
    {
        int number;
        cout<<"\n enter the size of the matrix";
        cout<<endl;;
        cin>>number;
        vector<vector<int>> m(number,vector<int>(number,0));
        for(int i=0;i<number;i++)
        {
            for(int j=0;j<number;j++)
            {
                cin>>m[i][j];
            }
        }

        Solution obj;
        vector<string> answer= obj.findPath(m);
        sort(answer.begin(),answer.end());
        if(answer.size()==0)
        cout<<-1;
        else
          {
            for(int i=0;i<answer.size();i++)
            cout<<answer[i]<<" ";
           cout<<endl; 
          }
        
    }
}