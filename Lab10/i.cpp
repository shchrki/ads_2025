#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        order.push_back(v);

        for (int u : adj[v])
        {
            indeg[u]--;
            if (indeg[u] == 0)
            {
                q.push(u);
            }
        }
    }

    if (order.size() == n)
    {
        cout << "Possible\n";
        for (int i = 0; i < n; ++i)
        {
            cout << order[i];
            if (i < n - 1)
                cout << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "Impossible\n";
    }

    return 0;
}