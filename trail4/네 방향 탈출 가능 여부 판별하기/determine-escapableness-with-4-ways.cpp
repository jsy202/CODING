#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[100][100];
int visited[104][104];
int dy[] = { -1, 0 , 1, 0};
int dx[] = {0 , 1, 0 , -1};

bool bfs(int sy, int sx)
{
    queue <pair<int,int>> q;
    visited[sy][sx] = 1;
    q.push({sy, sx});

    while(q.size())
    {
        int cy = q.front().first;
        int cx = q.front().second;

        if(cy == n - 1 && cx == m -1 ) return true;

        q.pop();
        for(int i = 0 ; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visited[ny][nx] == 1 || a[ny][nx] == 0) continue;
            visited[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    if(bfs(0,0)) cout << 1;
    else cout << 0;

    return 0;
}
