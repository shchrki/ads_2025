#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, rank;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    bool unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return false;

        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;

        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;

        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    DSU dsu(n);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> adj[i][j];

            if (i < j && adj[i][j] == 0)
                dsu.unite(i, j);
        }

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (adj[i][j] > 0)
                edges.push_back({adj[i][j], i, j});

    sort(edges.begin(), edges.end());

    long long totalCost = 0;

    for (auto [cost, i, j] : edges)
        if (dsu.unite(i, j))
            totalCost += cost;

    cout << totalCost << "\n";

    return 0;
}