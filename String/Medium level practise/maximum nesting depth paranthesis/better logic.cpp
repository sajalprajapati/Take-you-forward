#include <bits/stdc++.h>
using namespace std;

int maximumNestingDepth(string s)
{
    int maximum = 0;
    int Count = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
        {
            Count++;
        }
        else if(s[i] == ')')
        {
            Count--;
        }
        maximum = max(Count, maximum);
    }
    return maximum;
}

int main()
{
    string s;
    cout << "\nEnter your string: " << endl;
    cin >> s;

    int answer = maximumNestingDepth(s);
    cout << "\nThe maximum nesting parenthesis depth is: " << answer << endl;

    return 0;
}
