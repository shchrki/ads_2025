#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(const string &pat)
{
    int n = pat.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    while (i < n)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }
    return lps;
}

bool checkEqual(const string &s, int len)
{
    if (2 * len > s.size())
        return false;

    for (int i = 0; i < len; ++i)
    {
        if (s[i] != s[len + i])
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();
    int count = 0;

    for (int len = 1; 2 * len < n; ++len)
    {
        if (checkEqual(s, len))
        {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}