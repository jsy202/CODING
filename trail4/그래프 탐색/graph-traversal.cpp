#include <bits/stdc++.h> 
using namespace std;

int n, m;
int from[10000], to[10000];
int visited[10004];
vector <int> adj[10004];
int answer = 0;

void dfs(int here)
{
    visited[here] = 1;

    for(int next : adj[here])
    {
        if(visited[next] == 1) continue;
        answer++;
        dfs(next);
    }
}


int main() {
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
    }
    
    for(int i = 0 ; i < m; i++)
    {
        adj[from[i]].push_back(to[i]);
        adj[to[i]].push_back(from[i]);
    }
   
    
        
    dfs(1);
    
    cout << answer ;
    return 0;
}
