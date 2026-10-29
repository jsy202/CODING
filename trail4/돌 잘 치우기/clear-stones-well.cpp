#include <bits/stdc++.h>

using namespace std;

int n, k, m;
int grid[100][100];
int r[10000], c[10000];
int visited[104][104];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int mx= INT_MIN;
int ans;
vector<vector<int>> stones;


void bfs()  // 멀티소스 BFS에서는 sy, sx 필요없음
{
    ans = 0;
    queue<pair<int,int>> q;
    fill(&visited[0][0], &visited[0][0] + 104 * 104 , 0);

    for(int i = 0 ; i < k ; i++)
    {
        visited[r[i]][c[i]] = 1;
        q.push({r[i],c[i]});
        ans++;
    }

    while(q.size())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(visited[ny][nx] == 1 || grid[ny][nx] == 1) continue;
            visited[ny][nx] = 1;
            ans++;
            q.push({ny,nx});
        }
    }
}

void go(int start , int cnt)
{
    if(cnt == m)
    {
        bfs(); // 돌을 모두 제거하면 BFS 실행
        mx = max(mx, ans);
        return;
    }

    for(int i = start ; i < stones.size() ; i++)
    {
        int y = stones[i][0];
        int x = stones[i][1];
        grid[y][x] = 0;
        go(i + 1, cnt + 1);

        grid[y][x] = 1;
    }
    
}
    


int main() {
    cin >> n >> k >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) 
        {
            cin >> grid[i][j];

            if(grid[i][j] == 1) stones.push_back({i,j});
        }

    }
        

    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
    }
    
    
    go(0, 0);
    cout << mx;
    return 0;
}
