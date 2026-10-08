#include <bits/stdc++.h>

// 뱀은 0 

using namespace std;

int n, m;
int grid[100][100];
int dy[4] = {1 , 0};
int dx[4] = {0,1};
int visited[104][104];

bool dfs(int y, int x)
{
    if(y == n-1 && x == m-1) return true;
    visited[y][x] = 1;
    for(int i= 0 ; i < 2; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(visited[ny][nx] == 1 || grid[ny][nx] == 0) continue;
        
        // cout << ny << ' ' << nx << endl;
        if(dfs(ny,nx)) return true;
    }
    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    if(dfs(0, 0)) cout << 1;
    else cout << 0;
    
    return 0;
}
