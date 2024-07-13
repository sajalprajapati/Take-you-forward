#include<bits/stdc++.h>
using namespace std;
bool checker(vector<vector<int>> &matrix,int target)
{
    //in this binary search is not using but the property is using ..
    int row=0;
    int row_size=matrix.size();
    int col=matrix[0].size()-1;

    while(row<row_size and col>=0)
    {
        if(matrix[row][col]==target)
        {
            //we can store the row and column ...
            return true;
        }

        else if(matrix[row][col]<target)
        {
            row++;
        }
        else
        {
            col--;
        }
    }

    return false;
}
int main()
{
    int rows;
    cout<<"\nenter the number of rows"<<endl;
    cin>>rows;

    int cols;
    cout<<"\nenter the number of columns"<<endl;
    cin>>cols;

    vector<vector<int>> matrix(rows,vector<int>(cols));

    cout<<"\n enter the elements in the array"<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cin>>matrix[i][j];
        }
    }

    int target;
    cout<<"\n enter the target wish to search in the matrix"<<endl;
    cin>>target;

    bool answer=checker(matrix,target);
    if(answer==true)
    {
        cout<<"\n the element is found"<<endl;
    }
    else
    {
        cout<<"\n the element is not found "<<endl;
    }
}