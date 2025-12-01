#include <bits/stdc++.h>
using namespace std;

long long dijkstra(int start, int end, const vector<long long> &x, const vector<long long> &y)
{
    int n = x.size() - 1;
    vector<long long> minAge(n + 1, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    minAge[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [age, v] = pq.top();
        pq.pop();

        if (age > minAge[v])
            continue;

        for (int u = 1; u <= n; ++u)
        {
            if (u == v)
                continue;

            long long dist = abs(x[v] - x[u]) + abs(y[v] - y[u]);

            long long newAge = max(minAge[v], dist);

            if (newAge < minAge[u])
            {
                minAge[u] = newAge;
                pq.push({newAge, u});
            }
        }
    }

    return minAge[end];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> y[i];

    long long result = dijkstra(1, n, x, y);

    cout << result << "\n";

    return 0;
}