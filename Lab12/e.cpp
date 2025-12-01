#include <bits/stdc++.h>
using namespace std;

vector<int> findNegativeCycle(int n, const vector<tuple<int, int, int>> &edges)
{
    vector<long long> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);
    int cycleVertex = -1;

    for (int iter = 0; iter < n; ++iter)
    {
        cycleVertex = -1;

        for (auto [u, v, w] : edges)
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                cycleVertex = v;
            }
    }

    if (cycleVertex == -1)
        return {};

    for (int i = 0; i < n; ++i)
        cycleVertex = parent[cycleVertex];

    vector<int> cycle;
    int v = cycleVertex;

    do
    {
        cycle.push_back(v);
        v = parent[v];
    } while (v != cycleVertex);

    cycle.push_back(cycleVertex);
    reverse(cycle.begin(), cycle.end());

    return cycle;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<tuple<int, int, int>> edges;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int weight;
            cin >> weight;

            if (weight != 100000)
                edges.push_back({i, j, weight});
        }

    vector<int> cycle = findNegativeCycle(n, edges);

    if (cycle.empty())
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        cout << cycle.size() << "\n";
        for (int vertex : cycle)
            cout << vertex << " ";
        cout << "\n";
    }

    return 0;
}