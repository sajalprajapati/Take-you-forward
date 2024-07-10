#include <bits/stdc++.h>
using namespace std;

unsigned  long long int sqrt_function(int element) 
{
    unsigned long int lower = 0;
    unsigned long int higher = element;
    unsigned long int ans = -1;
    while (lower <= higher)
    {
        unsigned long int middle = lower + (higher - lower) / 2;

        if ((middle * middle) == element)
        {
            ans = middle;
            break; // Exit the loop if exact square root is found
        }
        else if ((middle * middle) > element)
        {
            higher = middle - 1;
        }
        else
        {
            ans = middle; // Update ans to keep track of the closest lower integer value
            lower = middle + 1;
        }
    }

    return ans;
}


int main()
{
    int element;
    cout<<"\n enter the elements  "<<endl;
    cin>>element;
    unsigned long int result=sqrt_function(element);
    cout<<"\n the approximate value is "<<result<<endl;
    

    return 0;
}

