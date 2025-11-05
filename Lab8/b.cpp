#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const ll BASE = 31;

ll fastPower(ll a, ll b)
{
    ll res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

vector<int> rabinKarp(const string &text, const string &pattern)
{
    vector<int> positions;
    int n = text.length();
    int m = pattern.length();

    if (m > n || m == 0)
        return positions;

    ll p_hash = 0, t_hash = 0;
    ll power_m = fastPower(BASE, m - 1);

    for (int i = 0; i < m; i++)
    {
        p_hash = (p_hash * BASE + pattern[i]) % MOD;
        t_hash = (t_hash * BASE + text[i]) % MOD;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (p_hash == t_hash)
        {
            positions.push_back(i);
        }

        if (i < n - m)
        {
            t_hash = (t_hash + MOD - (text[i] * power_m) % MOD) % MOD;
            t_hash = (t_hash * BASE) % MOD;
            t_hash = (t_hash + text[i + m]) % MOD;
        }
    }
    return positions;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string first, second, pattern;
    cin >> first >> second >> pattern;

    vector<int> pos1 = rabinKarp(first, pattern);
    vector<int> pos2 = rabinKarp(second, pattern);

    unordered_set<int> set2(pos2.begin(), pos2.end());

    int count = 0;
    for (int p : pos1)
    {
        if (set2.count(p))
            count++;
    }

    cout << count << endl;

    return 0;
}
