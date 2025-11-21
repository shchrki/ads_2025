#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> adj[i][j];
        }
    }

    for (int query = 0; query < q; ++query)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (adj[a][b] == 1 && adj[b][c] == 1 && adj[a][c] == 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}