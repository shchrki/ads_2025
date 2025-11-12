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

vector<int> KMPsearch(const string &text, const string &pat)
{
    vector<int> positions;
    int n = text.size();
    int m = pat.size();

    if (m > n)
        return positions;

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
            positions.push_back(i - j + 1);
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

    return positions;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, pattern;
    cin >> text >> pattern;

    vector<int> positions = KMPsearch(text, pattern);

    cout << positions.size() << "\n";
    for (int i = 0; i < positions.size(); ++i)
    {
        if (i > 0)
            cout << " ";
        cout << positions[i];
    }
    if (!positions.empty())
        cout << "\n";

    return 0;
}