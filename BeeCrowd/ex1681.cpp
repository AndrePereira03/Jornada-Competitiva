#include <bits/stdc++.h>
using namespace std;



// Retorna true se toda a string for igual a c
bool all_equal(const string& s, char c)
{
    for (char x : s) if (x != c) return false;
    return true;
}

int solve(const string& s)
{
    int n = s.size();
    if (n == 1) return 0;
    
    int res = INT_MAX;
    for (int mid = 1; mid < n; ++mid)
    {
        bool ok = true;
        char expected = s[0] == 'A' ? 'V' : 'A';
        for (int i = 0; i < mid; ++i)
        {
            if (s[i] != s[n-1-i])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            string next = s.substr(0, mid);
            for (char& x : next) x = (x == 'A' ? 'V' : 'A');
            res = min(res, 1 + solve(next));
        }
    }
    return res;
}

int main()
{
    string s;
    while (getline(cin, s))
    {
        cout << solve(s) << endl;
    }
    return 0;
}