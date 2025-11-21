#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B;
    cin >> A >> B;

    if (A == B)
    {
        cout << 0 << "\n\n";
        return 0;
    }

    map<long long, long long> parent;
    queue<long long> q;

    q.push(A);
    parent[A] = -1;

    while (!q.empty())
    {
        long long curr = q.front();
        q.pop();

        vector<long long> next_vals;

        if (curr <= B)
        {
            next_vals.push_back(curr * 2);
        }

        if (curr > 1)
        {
            next_vals.push_back(curr - 1);
        }

        for (long long next : next_vals)
        {
            if (parent.find(next) == parent.end())
            {
                parent[next] = curr;

                if (next == B)
                {
                    vector<long long> path;
                    long long node = B;
                    while (node != -1)
                    {
                        path.push_back(node);
                        node = parent[node];
                    }
                    reverse(path.begin(), path.end());

                    path.erase(path.begin());

                    cout << path.size() << "\n";
                    for (int i = 0; i < path.size(); ++i)
                    {
                        if (i > 0)
                            cout << " ";
                        cout << path[i];
                    }
                    cout << "\n";
                    return 0;
                }

                q.push(next);
            }
        }
    }

    return 0;
}
