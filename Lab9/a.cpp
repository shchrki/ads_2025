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

bool KMPsearch(const string &text, const string &pat)
{
    int n = text.size(), m = pat.size();

    if (m > n)
        return false;

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
            return true;
        }
        else if (i < n && pat[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    cin >> A >> B;

    int lenA = A.size();
    int lenB = B.size();

    if (KMPsearch(A, B))
    {
        cout << 1 << "\n";
        return 0;
    }

    int maxReps = (lenB / lenA) + 2;
    string repeated = A;

    for (int k = 2; k <= maxReps; ++k)
    {
        repeated += A;

        if (KMPsearch(repeated, B))
        {
            cout << k << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}
