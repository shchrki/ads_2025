#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    set<int> red_vertices;

    for (int i = 0; i < q; ++i)
    {
        int type, v;
        cin >> type >> v;

        if (type == 1)
        {

            red_vertices.insert(v);
        }
        else
        {

            if (red_vertices.empty())
            {
                cout << -1 << "\n";
                continue;
            }

            if (red_vertices.count(v))
            {
                cout << 0 << "\n";
                continue;
            }

            vector<int> dist(n + 1, -1);
            queue<int> bfs_queue;
            bfs_queue.push(v);
            dist[v] = 0;

            int min_dist = -1;
            while (!bfs_queue.empty())
            {
                int u = bfs_queue.front();
                bfs_queue.pop();

                if (red_vertices.count(u))
                {
                    min_dist = dist[u];
                    break;
                }

                for (int next : adj[u])
                {
                    if (dist[next] == -1)
                    {
                        dist[next] = dist[u] + 1;
                        bfs_queue.push(next);
                    }
                }
            }

            cout << min_dist << "\n";
        }
    }

    return 0;
}