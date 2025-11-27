#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, sz;

public:
    int components;

    DSU(int n)
    {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        components = 0;
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
        {
            return;
        }

        if (sz[x] < sz[y])
        {
            swap(x, y);
        }

        parent[y] = x;
        sz[x] += sz[y];
        components--;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> active(n + 1, false);
    vector<int> result(n);

    DSU dsu(n);

    for (int vertex = n; vertex >= 1; vertex--)
    {
        active[vertex] = true;
        dsu.components++;

        for (int neighbor : adj[vertex])
            if (active[neighbor])
                dsu.unite(vertex, neighbor);

        if (vertex > 1)
            result[vertex - 2] = dsu.components;
    }

    result[n - 1] = 0;

    for (int x : result)
        cout << x << "\n";

    return 0;
}