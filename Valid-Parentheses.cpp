#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;


bool isValid(string s)
{
    stack<char> stack;
    unordered_map<char, char> closeToOpen =
    {
        {')', '('},
        {']', '['},
        {'}', '{'},
    };


    for(char c : s)
    {
        if (closeToOpen.count(c))
        {
            if (!stack.empty() && stack.top() == closeToOpen[c])
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
        else
        {
            stack.push(c);
        }
    }

    return stack.empty();
}




int main()
{
    string s = "[(])";
    cout<<isValid(s)<<endl;;
}



