#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int bfs(int start, int end, const vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> dist(n, INF);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int u : adj[v])
            if (dist[u] == INF)
            {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
    }

    return dist[end];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> roadGraph(n + 1);
    vector<vector<int>> railGraph(n + 1);

    set<pair<int, int>> railways;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;

        if (u > v)
            swap(u, v);

        railways.insert({u, v});

        railGraph[u].push_back(v);
        railGraph[v].push_back(u);
    }

    for (int u = 1; u <= n; ++u)
        for (int v = u + 1; v <= n; ++v)
            if (railways.find({u, v}) == railways.end())
            {
                roadGraph[u].push_back(v);
                roadGraph[v].push_back(u);
            }

    int nugmanDist = bfs(1, n, roadGraph);
    int olzhasDist = bfs(1, n, railGraph);

    if (nugmanDist == INF || olzhasDist == INF)
        cout << -1 << "\n";
    else
        cout << max(nugmanDist, olzhasDist) << "\n";

    return 0;
}