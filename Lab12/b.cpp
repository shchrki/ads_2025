#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

vector<long long> dijkstra(int start, const vector<vector<pair<int, long long>>> &adj)
{
    int n = adj.size();
    vector<long long> dist(n, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [d, v] = pq.top();
        pq.pop();

        if (d > dist[v])
            continue;

        for (auto [u, w] : adj[v])
            if (dist[v] + w < dist[u])
            {
                dist[u] = dist[v] + w;
                pq.push({dist[u], u});
            }
    }

    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> adj(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int s, a, b, f;
    cin >> s >> a >> b >> f;

    auto distS = dijkstra(s, adj);
    auto distA = dijkstra(a, adj);
    auto distB = dijkstra(b, adj);
    auto distF = dijkstra(f, adj);

    long long route1 = distS[a] + distA[b] + distB[f];
    long long route2 = distS[b] + distB[a] + distA[f];

    long long result = min(route1, route2);

    if (result >= INF)
        cout << -1 << "\n";
    else
        cout << result << "\n";

    return 0;
}