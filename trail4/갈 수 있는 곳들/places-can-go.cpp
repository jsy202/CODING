#include <bits/stdc++.h> 

using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];
int visited[104][104];
int dy[] = {-1, 0 ,1 , 0};
int dx[] = {0, 1, 0, -1};

void bfs(int sy, int sx)
{
    queue <pair<int,int>> q;
    visited[sy][sx] = 1;
    q.push({sy,sx});
    while(q.size())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for(int i = 0;  i< 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny < 0 || nx < 0 || ny >= n || nx >=n) continue;
            if(visited[ny][nx] >= 1 || grid[ny][nx] == 1) continue;

            visited[ny][nx]= visited[cy][cx] + 1;
            q.push({ny,nx});
        }
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) cin >> r[i] >> c[i];

    for(int i = 0 ; i < k; i++)
    {
        bfs(r[i]-1, c[i]-1);
    }
    int cnt = 0;
    for(int i = 0 ; i <n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(visited[i][j] >= 1) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
