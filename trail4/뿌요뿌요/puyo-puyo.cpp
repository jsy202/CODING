
#include <bits/stdc++.h>
using namespace std;

int n;
int grid[100][100];
int visited[104][104];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int cnt;

void dfs(int y, int x)
{
    visited[y][x] = 1;

    int a = grid[y][x];

    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || nx >= n || ny >= n)
            continue;

        if(visited[ny][nx] == 1 || grid[ny][nx] != a)
            continue;

        cnt++;
        dfs(ny, nx);
    }
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int answer = 0;
    int mx = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(visited[i][j] == 1)
                continue;

            cnt = 1;
            dfs(i, j);

            if(cnt >= 4)
                answer++;

            mx = max(mx, cnt);
        }
    }

    cout << answer << ' ' << mx;

    return 0;
}
