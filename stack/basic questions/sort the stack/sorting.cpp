#include<bits/stdc++.h>
using namespace std;
void sortingFunction(stack<int> &s,int element)
{
    if(s.empty() or (s.top()<element))
    {
        s.push(element);
        return;
    }

    else
    {
        int a=s.top();
        s.pop();
        sortingFunction(s,element);
        s.push(a);
    }
}
void sorted(stack<int> &s)
{
    if(s.empty())
    return;

    int temp=s.top();
    s.pop();
    sorted(s);
    sortingFunction(s,temp);
}
int main()
{
    stack<int> s;
    cout<<"\n enter the element in the stack";
    int elementt;
    while(cin>>elementt)
    {
        s.push(elementt);
    }

    cin.clear(); // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    sorted(s);
     while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

}