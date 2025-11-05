#include <bits/stdc++.h>
using namespace std;

const long long BASE1 = 31;
const long long BASE2 = 37;
const long long MOD1 = 1e9 + 7;
const long long MOD2 = 1e9 + 9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.length();

    if (n == 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    unordered_set<long long> uniqueSubstrings;

    vector<long long> power1(n + 1), power2(n + 1);
    power1[0] = power2[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        power1[i] = (power1[i - 1] * BASE1) % MOD1;
        power2[i] = (power2[i - 1] * BASE2) % MOD2;
    }

    for (int i = 0; i < n; ++i)
    {
        long long hash1 = 0, hash2 = 0;

        for (int j = i; j < n; ++j)
        {
            hash1 = (hash1 + (long long)s[j] * power1[j - i]) % MOD1;
            hash2 = (hash2 + (long long)s[j] * power2[j - i]) % MOD2;

            long long combined = hash1 * MOD2 + hash2;
            uniqueSubstrings.insert(combined);
        }
    }

    cout << uniqueSubstrings.size() << "\n";

    return 0;
}