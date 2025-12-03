#include <bits/stdc++.h>
using namespace std;

void floyd(vector<vector<long long>> &dist, int k)
{
    int n = dist.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (dist[i][k] + dist[k][j] < dist[i][j])
                dist[i][j] = dist[i][k] + dist[k][j];
}

long long calculateDiameter(const vector<vector<long long>> &dist, const vector<bool> &active)
{
    int n = dist.size();
    long long diameter = 0;

    for (int i = 0; i < n; ++i)
    {
        if (!active[i])
            continue;

        for (int j = 0; j < n; ++j)
        {
            if (!active[j])
                continue;

            diameter = max(diameter, dist[i][j]);
        }
    }

    return diameter;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<long long>> dist(n, vector<long long>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> dist[i][j];

    vector<int> addOrder(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> addOrder[i];
        addOrder[i]--;
    }

    vector<long long> results(n);
    vector<bool> active(n, false);

    for (int step = 0; step < n; ++step)
    {
        int vertex = addOrder[step];
        active[vertex] = true;

        floyd(dist, vertex);
        results[step] = calculateDiameter(dist, active);
    }

    for (int i = 0; i < n; ++i)
        cout << results[i] << "\n";

    return 0;
}