#include <bits/stdc++.h>

using namespace std;



int N, M;
int grid[50][50];
int visited[104][104];
int dy[] = {-1, 0 ,1 ,0};
int dx[] = {0 ,1 , 0 , -1};
int k ;
int cnt =  0;

void dfs(int y ,int x)
{
    visited[y][x] = 1;
    for(int i = 0 ; i < 4 ; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(visited[ny][nx] == 1 || grid[ny][nx] <= k) continue;
        dfs(ny, nx);
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    int mx = 0; // 안전 구역 갯수의 최대값
    int mxk = 1; // k값
    int cnt = 0; // 안전구역 갯수
    for(int h = 1 ; h <= 100 ; h++){
        cnt = 0;
        fill(&visited[0][0], &visited[0][0] + 104*104, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {       
                k = h;
                if(visited[i][j] == 1 ||  grid[i][j] <= k) continue;
                cnt++;
                dfs(i, j);
        }
    }
    if(cnt > mx){
        mx = cnt ; mxk = k;
    }
}
    cout << mxk << ' ' << mx;
    return 0;
}
