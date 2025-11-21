#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &component)
{
    visited[v] = true;
    component.push_back(v);

    for (int u : adj[v])
    {
        if (!visited[u])
        {
            dfs(u, adj, visited, component);
        }
    }
}

int countChildren(int v, int parent, vector<vector<int>> &tree, vector<int> &childCount)
{
    int count = 0;

    for (int u : tree[v])
    {
        if (u != parent)
        {
            count++;
            count += countChildren(u, v, tree, childCount);
        }
    }

    childCount[v] = tree[v].size() - (parent != -1 ? 1 : 0);
    return count;
}

void markBigFam(int v, int parent, vector<vector<int>> &tree, vector<int> &childCount, vector<bool> &isBigFam)
{
    if (parent == -1)
    {
        
        isBigFam[v] = true;
    }
    else
    {
        
        if (childCount[v] > childCount[parent])
        {
            isBigFam[v] = true;
        }
    }

    for (int u : tree[v])
    {
        if (u != parent)
        {
            markBigFam(u, v, tree, childCount, isBigFam);
        }
    }
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
        adj[y].push_back(x);
    }

    vector<bool> visited(n + 1, false);
    vector<bool> isBigFam(n + 1, false);

    
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, adj, visited, component);

            
            int root = *min_element(component.begin(), component.end());

            
            vector<vector<int>> tree(n + 1);
            vector<bool> treeVisited(n + 1, false);
            queue<int> q;
            q.push(root);
            treeVisited[root] = true;

            while (!q.empty())
            {
                int v = q.front();
                q.pop();

                for (int u : adj[v])
                {
                    if (!treeVisited[u])
                    {
                        treeVisited[u] = true;
                        tree[v].push_back(u);
                        tree[u].push_back(v);
                        q.push(u);
                    }
                }
            }

            
            vector<int> childCount(n + 1, 0);
            countChildren(root, -1, tree, childCount);

            
            markBigFam(root, -1, tree, childCount, isBigFam);
        }
    }

    
    int result = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (isBigFam[i])
        {
            result++;
        }
    }

    cout << result << "\n";

    return 0;
}