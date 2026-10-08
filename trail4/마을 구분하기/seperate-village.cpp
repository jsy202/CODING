#include <bits/stdc++.h>

using namespace std;

int n;
int grid[25][25];
int dy[]= {-1,0,1,0};
int dx[] = {0,1,0,-1};
int visited[30][30];
int cnt;

int dfs(int y, int x)
{ 
    visited[y][x] = 1;
    for(int i = 0 ; i< 4 ; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || nx >= n || ny >= n) continue;
        if(visited[ny][nx] == 1 || grid[ny][nx] == 0) continue;
        cnt ++;
        dfs(ny, nx);
    }
    return cnt;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<int> v;
    int answer  = 0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cnt = 0;
            if(visited[i][j] == 1 || grid[i][j] == 0) continue;
            v.push_back(dfs(i,j));
            answer ++;
        }
    }
    sort(v.begin(), v.end());
    cout << answer << endl;
    for(int a : v)
    {
        cout << a+1 << endl;
    }

    return 0;
}
