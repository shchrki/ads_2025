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

int KMPfindFirst(const string &text, const string &pat)
{
    int n = text.size(), m = pat.size();

    if (m > n)
        return -1;

    vector<int> lps = computeLPS(pat);
    int i = 0, j = 0;

    while (i < n)
    {
        if (pat[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            return i - j;
        }
        else if (i < n && pat[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();

    if (s1.size() != s2.size())
    {
        cout << -1 << "\n";
        return 0;
    }

    if (s1 == s2)
    {
        cout << 0 << "\n";
        return 0;
    }

    string doubled = s1 + s1;
    int pos = KMPfindFirst(doubled, s2);

    if (pos == -1 || pos == 0)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << (n - pos) << "\n";
    }

    return 0;
}
