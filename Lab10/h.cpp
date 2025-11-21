#include <bits/stdc++.h>
using namespace std;

void dfs(vector<string> &grid, int i, int j, int n, int m)
{

    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0')
    {
        return;
    }

    grid[i][j] = '0';

    dfs(grid, i - 1, j, n, m);
    dfs(grid, i + 1, j, n, m);
    dfs(grid, i, j - 1, n, m);
    dfs(grid, i, j + 1, n, m);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> grid[i];
    }

    int islands = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == '1')
            {

                islands++;

                dfs(grid, i, j, n, m);
            }
        }
    }

    cout << islands << "\n";

    return 0;
}