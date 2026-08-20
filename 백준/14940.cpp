#include <bits/stdc++.h>
using namespace std;

int visited[1004][1004];
int a[1004][1004];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;

void bfs(int sy, int sx)    // 기초적인 BFS 템플릿 그대로 
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

    for(int i = 0; i < n; i++)   // 2를 찾으면 sy와 sx의 좌표를 고정
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

    for(int i = 0; i < n; i++)  // 0이면 0으로 출력, visited 가 0 이 아니면 거리 출력 , 이 둘다 아니면 -1 출력
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
