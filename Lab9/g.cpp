#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(const string &s)
{
    int n = s.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    while (i < n)
    {
        if (s[i] == s[len])
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();
    vector<int> lps = computeLPS(s);

    int period = n - lps[n - 1];

    cout << period << "\n";

    return 0;
}