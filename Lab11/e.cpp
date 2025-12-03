#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, rank;

public:
    int components;

    DSU(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        components = 0;
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return;

        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;

        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;

        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

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