#include <bits/stdc++.h>
using namespace std;

const long long BASE = 31;
const long long MOD = 1e9 + 7;

vector<int> rabinKarp(const string &text, const string &pattern)
{
    vector<int> positions;
    int n = text.size();
    int m = pattern.size();

    if (m > n)
        return positions;

    long long patternHash = 0;
    long long powerM = 1;

    for (int i = 0; i < m; ++i)
    {
        patternHash = (patternHash * BASE + pattern[i]) % MOD;
        if (i < m - 1)
            powerM = (powerM * BASE) % MOD;
    }

    long long textHash = 0;
    for (int i = 0; i < m; ++i)
    {
        textHash = (textHash * BASE + text[i]) % MOD;
    }

    if (textHash == patternHash)
    {
        bool match = true;
        for (int j = 0; j < m; ++j)
        {
            if (text[j] != pattern[j])
            {
                match = false;
                break;
            }
        }
        if (match)
            positions.push_back(0);
    }

    for (int i = m; i < n; ++i)
    {

        textHash = (textHash - (long long)text[i - m] * powerM % MOD + MOD) % MOD;
        textHash = (textHash * BASE + text[i]) % MOD;

        if (textHash == patternHash)
        {

            bool match = true;
            int start = i - m + 1;
            for (int j = 0; j < m; ++j)
            {
                if (text[start + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
                positions.push_back(start);
        }
    }

    return positions;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int L, R;
        cin >> L >> R;
        string pattern = s.substr(L - 1, R - L + 1);
        cout << rabinKarp(s, pattern).size() << endl;
    }
}