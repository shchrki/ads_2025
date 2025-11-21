#include <bits/stdc++.h>
using namespace std;

vector<int> cycle;
vector<int> color;
vector<int> parent;

bool findCycle(int v, vector<vector<int>> &adj)
{
    color[v] = 1;

    for (int u : adj[v])
    {
        if (color[u] == 0)
        {
            parent[u] = v;
            if (findCycle(u, adj))
            {
                return true;
            }
        }
        else if (color[u] == 1)
        {

            cycle.push_back(u);
            int curr = v;
            while (curr != u)
            {
                cycle.push_back(curr);
                curr = parent[curr];
            }
            reverse(cycle.begin(), cycle.end());
            return true;
        }
    }

    color[v] = 2;
    return false;
}

bool isAcyclic(int n, vector<vector<int>> &adj, int skipFrom, int skipTo)
{
    vector<int> indeg(n + 1, 0);

    for (int v = 1; v <= n; ++v)
    {
        for (int u : adj[v])
        {
            if (v == skipFrom && u == skipTo)
            {
                continue;
            }
            indeg[u]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    int processed = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        processed++;

        for (int u : adj[v])
        {
            if (v == skipFrom && u == skipTo)
            {
                continue;
            }

            indeg[u]--;
            if (indeg[u] == 0)
            {
                q.push(u);
            }
        }
    }

    return processed == n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    color.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    bool hasCycle = false;
    for (int i = 1; i <= n; ++i)
    {
        if (color[i] == 0)
        {
            if (findCycle(i, adj))
            {
                hasCycle = true;
                break;
            }
        }
    }

    if (!hasCycle)
    {
        cout << "YES\n";
        return 0;
    }

    int cycleSize = cycle.size();
    for (int i = 0; i < cycleSize; ++i)
    {
        int from = cycle[i];
        int to = cycle[(i + 1) % cycleSize];

        if (isAcyclic(n, adj, from, to))
        {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
