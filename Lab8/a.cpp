#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

string Hash(string s)
{
    long long num = 1;
    long long res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        res += ((s[i] - 47) * num) % MOD;
        num %= MOD;
        num *= 11;
    }
    return to_string(res % MOD);
}

int main()
{
    int n;
    cin >> n;

    vector<string> v;
    map<string, bool> mp;
    for (int i = 0; i < 2 * n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
        mp[s] = true;
    }
    int cnt = 0;

    for (auto &i : v)
    {
        string t;
        t = Hash(i);
        if (mp[t] == true)
        {
            cout << "Hash of string \"" << i << "\" is " << t << endl;
            cnt++;
        }
        if (cnt == n)
        {
            return 0;
        }
    }
}