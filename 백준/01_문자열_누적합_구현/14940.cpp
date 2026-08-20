#include <bits/stdc++.h>
using namespace std;

int visited[1004][1004];
int a[1004][1004];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;

void bfs(int sy, int sx)
{
    queue<pair<int, int>> q;

    visited[sy][sx] = 1;
    q.push({sy, sx});

    while(q.size())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visited[ny][nx] || a[ny][nx] == 0) continue;

            visited[ny][nx] = visited[cy][cx] + 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    int sy, sx;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];

            if(a[i][j] == 2)
            {
                sy = i;
                sx = j;
            }
        }
    }

    bfs(sy, sx);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == 0)
                cout << 0 << ' ';
            else if(visited[i][j])
                cout << visited[i][j] - 1 << ' ';
            else
                cout << -1 << ' ';
        }

        cout << '\n';
    }

    return 0;
}
