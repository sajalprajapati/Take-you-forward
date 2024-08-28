class Solution {
public: 
    int helper(int i,int j,int n,vector<vector<int>>& triangle)
    {
        if(i==n-1)
        {
            return triangle[i][j];//we don't have here a fixed ending ....
        }

        int down=triangle[i][j]+helper(i+1,j,n,triangle);
        int diagonally=triangle[i][j]+helper(i+1,j+1,n,triangle);

        return min(down,diagonally);
    } 

    int minimumTotal(vector<vector<int>>& triangle) 
    {
      int n=triangle.size();
      return helper(0,0,n,triangle);    
    }
};