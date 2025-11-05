#include <bits/stdc++.h>
using namespace std;

const long long BASE = 31;
const long long MOD = 1e9 + 7;

map<int, set<long long>> getAllSubstringHashes(const string &s)
{
    map<int, set<long long>> result;
    int n = s.size();

    vector<long long> power(n + 1);
    power[0] = 1;
    for (int i = 1; i <= n; ++i)
        power[i] = (power[i - 1] * BASE) % MOD;

    for (int i = 0; i < n; ++i)
    {
        long long hash = 0;
        for (int j = i; j < n; ++j)
        {
            hash = (hash + (long long)s[j] * power[j - i]) % MOD;
            int len = j - i + 1;
            result[len].insert(hash);
        }
    }

    return result;
}

long long computeHash(const string &s)
{
    long long hash = 0;
    long long power = 1;
    for (char c : s)
    {
        hash = (hash + (long long)c * power) % MOD;
        power = (power * BASE) % MOD;
    }
    return hash;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; ++i)
        cin >> strings[i];

    int minIdx = 0;
    for (int i = 1; i < n; ++i)
    {
        if (strings[i].size() < strings[minIdx].size())
            minIdx = i;
    }

    string shortest = strings[minIdx];

    map<int, set<long long>> shortestHashes = getAllSubstringHashes(shortest);

    for (int i = 0; i < n; ++i)
    {
        if (i == minIdx)
            continue;

        map<int, set<long long>> currentHashes = getAllSubstringHashes(strings[i]);

        for (auto &[len, hashes] : shortestHashes)
        {
            if (currentHashes.find(len) != currentHashes.end())
            {
                set<long long> intersection;
                set_intersection(hashes.begin(), hashes.end(),
                                 currentHashes[len].begin(), currentHashes[len].end(),
                                 inserter(intersection, intersection.begin()));
                hashes = intersection;
            }
            else
            {
                hashes.clear();
            }
        }
    }

    string result = "";
    for (auto it = shortestHashes.rbegin(); it != shortestHashes.rend(); ++it)
    {
        int len = it->first;
        const set<long long> &hashes = it->second;

        if (!hashes.empty())
        {
            long long targetHash = *hashes.begin();

            for (int start = 0; start <= (int)shortest.size() - len; ++start)
            {
                string substr = shortest.substr(start, len);
                if (computeHash(substr) == targetHash)
                {
                    result = substr;
                    break;
                }
            }
            break;
        }
    }

    cout << result << "\n";

    return 0;
}
