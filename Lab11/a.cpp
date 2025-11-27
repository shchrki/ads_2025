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

    vector<tuple<int, int, int>> segments;
    for (int i = 0; i < m; ++i)
    {
        int l, r, c;
        cin >> l >> r >> c;
        segments.push_back({c, l, r});
    }

    sort(segments.begin(), segments.end());

    DSU dsu(n);
    long long totalCost = 0;

    vector<int> next(n + 2);
    iota(next.begin(), next.end(), 0);

    for (auto [cost, l, r] : segments)
    {
        int i = l;
        while (i < r)
        {
            if (dsu.unite(i, i + 1))
                totalCost += cost;

            int tmp = i;
            i = next[i + 1];
            next[tmp] = r;
        }
    }

    cout << totalCost << "\n";

    return 0;
}