#include <iostream>
#include <vector>

using namespace std;

int ret = 0;
int n, m;

vector<vector<int>> grid;
vector<pair<int, int>> points;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int visited[10][10];

void dfs(int y, int x, int idx)
{
    // 현재 찾아야 하는 지점에 도착
    if(y == points[idx].first && x == points[idx].second)
    {
        // 마지막 목적지까지 도착
        if(idx == m - 1)
        {
            ret++;
            return;
        }

        // 다음 목적지를 찾으러 감
        idx++;
    }

    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        // 맵 밖
        if(ny < 0 || ny >= n || nx < 0 || nx >= n)
            continue;

        // 이미 방문했거나 벽
        if(visited[ny][nx] || grid[ny][nx] == 1)
            continue;

        // 선택
        visited[ny][nx] = 1;

        // 탐색
        dfs(ny, nx, idx);

        // 원복
        visited[ny][nx] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    grid.resize(n, vector<int>(n));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    points.resize(m);

    for(int i = 0; i < m; i++)
    {
        int y, x;
        cin >> y >> x;

        points[i] = {y - 1, x - 1};
    }

    // 시작점 방문 처리
    visited[points[0].first][points[0].second] = 1;

    // points[0]은 이미 서 있으므로 다음 목적지는 points[1]
    dfs(points[0].first, points[0].second, 1);

    cout << ret << '\n';

    return 0;
}