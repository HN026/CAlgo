#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

string CommonPrefix(vector<string> &strs)
{
    string ansfinal = "";
    int minlength = strs[0].length();
    for (int i = 0; i < strs.size(); i++)
    {
        if (strs[i].length() < minlength)
        {
            minlength = strs[i].length();
        }
        else
        {
            continue;
        }
    }

    string ref = strs[0];

    for (int i = 0; i < minlength; i++)
    {
        int count = 0;
        for (int j = 0; j < strs.size(); j++)
        {
            if (strs[j][i] == ref[i])
            {
                count++;
            }
            else{
                return ansfinal;
            }
        }
        if (count == strs.size())
        {
            ansfinal += ref[i];
        }
    }

    return ansfinal;
}

int main()
{

    vector<string> strs = {"cir", "car"};
    cout << CommonPrefix(strs);
    return 0;
}