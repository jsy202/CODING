#include <bits/stdc++.h>
using namespace std;
int n , m ;
char a[604][604];
int visited[604][604];
int dy[] = {-1, 0 , 1 ,0};
int dx[] = { 0 , 1 , 0 , -1};
int cnt = 0 ; 

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for(int i = 0 ; i < 4 ; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(visited[ny][nx] == 1 || a[ny][nx] == 'X') continue;
        if(a[ny][nx] == 'P') cnt++;
        dfs(ny,nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int rx, ry;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(a[i][j] == 'I'){
                ry = i;
                rx = j;
            }
        }
    }
    dfs(ry, rx);
    if(cnt == 0) cout << "TT";
    else cout << cnt;
    return 0;
}

/* =================================================================
   [BFS 대체 풀이]
   실전 코딩 테스트에서 N, M이 수백 이상으로 커 스택 오버플로우가 걱정될 때
   dfs 함수 대신 아래의 bfs 함수를 만들어 호출하면 됩니다.
   =================================================================

void bfs(int sy, int sx)
{
    queue<pair<int, int>> q;
    
    // 시작 지점 큐 삽입 및 방문 처리
    q.push({sy, sx});
    visited[sy][sx] = 1;

    while(!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(visited[ny][nx] == 1 || a[ny][nx] == 'X') continue;

            if(a[ny][nx] == 'P') cnt++;

            // 큐에 넣는 시점에 즉시 방문 체크를 해야 중복 push(메모리 초과)를 막음
            visited[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
}

// main 함수에서는 dfs(ry, rx); 대신 bfs(ry, rx); 만 호출하면 동일하게 동작합니다.
================================================================= */
