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

    while (true)
    {
        int N;
        cin >> N;

        if (N == 0)
            break;

        vector<string> patterns(N);
        for (int i = 0; i < N; ++i)
            cin >> patterns[i];

        string text;
        cin >> text;

        vector<pair<string, int>> result;
        result.reserve(N);

        for (const auto &pattern : patterns)
        {
            int count = rabinKarp(text, pattern).size();
            result.emplace_back(pattern, count);
        }

        stable_sort(result.begin(), result.end(),
                    [](const auto &a, const auto &b)
                    {
                        return a.second > b.second;
                    });

        if (!result.empty())
        {
            int maxCount = result[0].second;
            cout << maxCount << "\n";
            for (const auto &p : result)
            {
                if (p.second == maxCount)
                    cout << p.first << "\n";
                else
                    break;
            }
        }
    }
}