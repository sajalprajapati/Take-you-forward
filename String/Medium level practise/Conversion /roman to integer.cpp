#include <bits/stdc++.h>
using namespace std;

int Integer(char ch)
{
    if((ch == 'I') or (ch=='i')) return 1;
    if((ch == 'V') or (ch=='v')) return 5;
    if((ch == 'X') or (ch=='x')) return 10;
    if((ch == 'L') or (ch=='l')) return 50;
    if((ch == 'C')or (ch=='c')) return 100;
    if((ch == 'D')or (ch=='d')) return 500;
    if((ch == 'M')or (ch=='m')) return 1000;
    return 0;  // This line is added for safety, though ideally it should never be reached.
}

int Roman(string s)
{
    int n = s.size();
    int ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        int v1 = Integer(s[i]);
        int v2 = (i < n - 1) ? Integer(s[i + 1]) : 0;
        
        if(v1 >= v2)
        {
            ans += v1;
        }
        else
        {
            ans -= v1;
        }
    }

    return ans;
}

int main()
{
    string s;
    cout << "Enter the Roman numeral string: ";
    cin >> s;

    int answer = Roman(s);
    cout << "The integer value is: " << answer << endl;

    return 0;
}
