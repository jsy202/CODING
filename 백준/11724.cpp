#include <bits/stdc++.h>
using namespace std;

int visited[1004];
vector<int> adj[1004];

void dfs(int here)
{
    visited[here] = 1;

    for(int there : adj[here])
    {
        if(visited[there]) continue;

        dfs(there);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ret = 0;

    for(int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;

        dfs(i);
        ret++;
    }

    cout << ret << '\n';

    return 0;
}
