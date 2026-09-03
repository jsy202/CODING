#include<vector>
#include <bits/stdc++.h> 
using namespace std;

const int dy[] = {-1, 0 , 1 , 0};
const int dx[] = {0, 1, 0 ,-1};
int visited[101][101];

int solution(vector<vector<int> > maps)
{
    fill(&visited[0][0], &visited[0][0]+ 101 * 101, 0);
    int m = maps[0].size();
    int n = maps.size();
    queue <pair<int , int>> q;
    visited[0][0] = 1 ;
    q.push({0,0});
    
    while(q.size())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
    
    for(int i = 0 ; i < 4; i++)
    {
        int ny = cy + dy[i];
        int nx = cx + dx[i];
        
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(visited[ny][nx] >= 1) continue;
        if(maps[ny][nx] == 0) continue;
        
        visited[ny][nx] = visited[cy][cx] + 1;  
        q.push({ny, nx});
    }
    }
    if(visited[n-1][m-1] == 0 ) return -1 ;
    return visited[n-1][m-1];
}
