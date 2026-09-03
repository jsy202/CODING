#include <bits/stdc++.h>
using namespace std;

int visited[104];
vector<int> adj[104];

int a, b;

void bfs(int here)
{
    queue<int> q;

    visited[here] = 1;
    q.push(here);

    while(q.size())
    {
        int there = q.front();
        q.pop();

        for(int next : adj[there])
        {
            if(visited[next]) continue;

            visited[next] = visited[there] + 1;
            q.push(next);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cin >> a >> b;

    int k;
    cin >> k;

    for(int i = 0; i < k; i++)
    {
        int p, j;
        cin >> p >> j;

        adj[p].push_back(j);
        adj[j].push_back(p);
    }

    bfs(a);

    if(visited[b] == 0)
        cout << -1;
    else
        cout << visited[b] - 1;

    return 0;
}
