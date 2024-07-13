#include<bits/stdc++.h>
using namespace std;
bool checker(vector<vector<int>> &matrix,int target)
{
    int n=matrix.size(); //this provide the number of rows.
    int m=matrix[0].size(); //this provide the number of columns;

    int lower=0;
    int higher=(n*m)-1;

    while(lower<=higher)
    {
        int middle=lower+(higher-lower)/2;

        int row=middle/m; //where is the number of columns present in the 2-D matrix...
        int col=middle%m;

        if(matrix[row][col]==target)
        {
            return true;
        }
        else if(matrix[row][col]<target)
        {
            lower=middle+1;
        }
        else 
        {
            higher=middle+1;
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