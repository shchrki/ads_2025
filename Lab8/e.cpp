#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> hash(n);
    for (int i = 0; i < n; ++i)
        cin >> hash[i];

    string result;

    for (int i = 0; i < n; ++i)
    {
        long long diff;
        if (i == 0)
            diff = hash[0];
        else
            diff = hash[i] - hash[i - 1];

        long long power = 1LL << i;
        long long charCode = diff / power + 97;

        result += (char)charCode;
    }

    cout << result << "\n";

    return 0;
}
