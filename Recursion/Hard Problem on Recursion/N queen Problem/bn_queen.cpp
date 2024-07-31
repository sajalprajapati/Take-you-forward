#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> answer;
bool isValid(vector<string> &board,int row,int column)
{
    //checking vertically upward
  for(int i=row-1;i>=0;i--)
  {
    if(board[i][column]=='Q')
    {
        return false;
    }
  }

  //checking vertically left diagonally....
  for(int i=row-1,j=column-1;i>=0 and j>=0;i--,j-- )
  {
    if(board[i][j]=='Q')
    return false;
  }


  //vectically right diagonally..
  for(int i=row-1,j=col+1;i>=0 and j<board[0].length();i--,j++)
  {
    if(board[i][j]=='Q')
    return false;
  }
}

void solve(vector<string> &board,int row,int n)
{
  if(row==n)
  {
    answer.push_back(board);
    return;
  }


  for(int column=0;column<n;column++)
  {
    if(isVlaid(board,row,column)) //this function will check that whether at which point we are putting the queen at should not be attacked by any other queen placed before
    {
        board[row][column]='Queen';
    /*    col=0  col=1  col=2
         |--------------------|
  row=0  | Queen  .       .   |   
  row=1  | .      .       .   |
  row=2  | .      .       .   |      
         |--------------------| 
        */

        solve(board,row+1,n); //yeah humrha dusri row ke liye hai...
        board[row][column]='.';
    }
  }
}

vector<vector<string>> solveNQueens(int n) 
{
        //sabse pehle board bano.....
        //jaise agar n=3 ke barabar hai toh chessboard 3*3=9 ka hoga.
        vector<string> board(n,string(n,'.'));
        /*
         |--------------------|
         | .      .       .   |   
         | .      .       .   |
         | .      .       .   |      <-------------------this is our chessboard made up of string only.
         |--------------------| 
        */
 
        solve(board,0,n); //<---------------------we are starting from the first row......
        return answer;
}

int main()
{
    solveNQueens(3);
    for(auto element:answer)
    {
        for(const auto element1:element)
        {
            for(const auto element2:element1)
            {
             for(const auto element3:element2)
             {
                cout<<element3;
             }
            }
        }
    }
}