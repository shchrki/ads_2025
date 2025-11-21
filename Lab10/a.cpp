#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    queue<pair<int, int>> q;
    int mushrooms = 0;
    int time = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 2)
                q.push({i, j});
            else if (grid[i][j] == 1)
                mushrooms++;
        }
    }

    if (mushrooms == 0)
    {
        cout << 0;
        return 0;
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty())
    {
        int size = q.size();
        bool changed = false;

        for (int i = 0; i < size; i++)
        {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                if (grid[nx][ny] == 1)
                {
                    grid[nx][ny] = 2;
                    mushrooms--;
                    q.push({nx, ny});
                    changed = true;
                }
            }
        }

        if (changed)
            time++;
    }

    if (mushrooms > 0)
        cout << -1;
    else
        cout << time;

    return 0;
}
