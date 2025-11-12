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

int KMPcount(const string &text, const string &pat)
{
    int n = text.size(), m = pat.size();

    if (m > n)
        return 0;

    vector<int> lps = computeLPS(pat);
    int i = 0, j = 0;
    int count = 0;

    while (i < n)
    {
        if (pat[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            count++;
            j = lps[j - 1];
        }
        else if (i < n && pat[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int K;
    cin >> s >> K;

    string T;
    cin >> T;

    int occurrences = KMPcount(T, s);

    if (occurrences >= K)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}