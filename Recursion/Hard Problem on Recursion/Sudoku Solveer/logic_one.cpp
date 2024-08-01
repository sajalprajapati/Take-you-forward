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


      //validating 3*3 box;
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