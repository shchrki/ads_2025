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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        long long k;
        cin >> s >> k;

        int n = s.size();
        vector<int> lps = computeLPS(s);

        int period = n - lps[n - 1];

        long long length = (long long)n + (k - 1) * period;

        cout << length << "\n";
    }

    return 0;
}