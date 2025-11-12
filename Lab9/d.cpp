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

int findOverlap(const string &prev, const string &city)
{
    string prevLower = prev;
    string cityLower = city;

    transform(prevLower.begin(), prevLower.end(), prevLower.begin(), ::tolower);
    transform(cityLower.begin(), cityLower.end(), cityLower.begin(), ::tolower);

    string combined = cityLower + "#" + prevLower;
    vector<int> lps = computeLPS(combined);

    return lps[combined.size() - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string P;
    cin >> P;

    int N;
    cin >> N;

    vector<string> cities(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> cities[i];
    }

    int maxOverlap = 0;
    vector<int> overlaps(N);

    for (int i = 0; i < N; ++i)
    {
        overlaps[i] = findOverlap(P, cities[i]);
        maxOverlap = max(maxOverlap, overlaps[i]);
    }

        if (maxOverlap == 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    vector<string> result;
    for (int i = 0; i < N; ++i)
    {
        if (overlaps[i] == maxOverlap)
        {
            result.push_back(cities[i]);
        }
    }

    cout << result.size() << "\n";
    for (const string &city : result)
    {
        cout << city << "\n";
    }

    return 0;
}