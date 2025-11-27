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

    int n, m;
    cin >> n >> m;

    int x, y;
    cin >> x >> y;

    vector<tuple<long long, int, int>> edges;

    for (int i = 0; i < m; ++i)
    {
        string type;
        int a, b, c;
        cin >> type >> a >> b >> c;

        long long cost;
        if (type == "big")
            cost = (long long)c * x;

        else if (type == "small")
            cost = (long long)c * y;

        else
            cost = (long long)c * min(x, y);

        edges.push_back({cost, a, b});
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    long long totalCost = 0;
    int edgesAdded = 0;

    for (auto [cost, a, b] : edges)
        if (dsu.unite(a, b))
        {
            totalCost += cost;
            edgesAdded++;

            if (edgesAdded == n - 1)
            {
                break;
            }
        }

    cout << totalCost << "\n";

    return 0;
};