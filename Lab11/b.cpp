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

    vector<long long> d(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> d[i];

    vector<tuple<long long, int, int>> edges;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            long long cost = d[i] + d[j];
            edges.push_back({cost, i, j});
        }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    long long totalCost = 0;
    int edgesAdded = 0;

    for (auto [cost, i, j] : edges)
        if (dsu.unite(i, j))
        {
            totalCost += cost;
            edgesAdded++;

            if (edgesAdded == n - 1)
                break;
        }

    cout << totalCost << "\n";

    return 0;
}