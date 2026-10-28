#include <bits/stdc++.h> 

using namespace std;

int n, k;
int grid[100][100];
int r, c;
int visited[104][104];
int dy[] = {-1, 0 , 1, 0};
int dx[] = {0,1,0,-1};
int answerx, answery;


bool bfs(int sy, int sx)  // bool로 만들었습니다. -> 이동이 가능한지 보려고 
{

    fill(&visited[0][0], &visited[0][0] + 104*104, 0);
    queue<pair<int,int>> q; 
    visited[sy][sx] = 1;
    q.push({sy,sx});

    int mx = INT_MIN; // 갈수있는 칸중 최대인 칸을 골라야해서 
    bool fnd = false; // BFS로 갈수있는 칸이 있기는 한가 보려고 

    while(q.size())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0; i < 4 ; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(visited[ny][nx] == 1) continue;
            if(grid[ny][nx] >= grid[sy][sx]) continue;

            visited[ny][nx] = 1;
            q.push({ny,nx});

            if(grid[ny][nx] > mx) // 얘는 무조건 한번은 거쳐야함
            {
                mx= grid[ny][nx];
                answerx = nx;
                answery = ny;
                fnd = true; 
            }
            else if(grid[ny][nx] == mx)
            {
                if(ny < answery || (ny == answery && nx < answerx))
                {
                    answery = ny;
                    answerx = nx;
                }
            }
        }
    }
    return fnd;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }


    cin >> r >> c;
    r-- ; c-- ;
    for(int i = 0 ; i < k ; i++)
    {
        if(!bfs(r,c)) break; 

        r = answery ; 
        c = answerx;   // 움직일수있고 하면 이렇게 변환 (이동했던 칸을 다시 맥여야함)
    }


    cout << r + 1<< ' ' << c + 1;
    return 0;
}
