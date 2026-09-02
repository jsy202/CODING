#include <bits/stdc++.h>
using namespace std;

int visited[101];
vector<int> adj[101]; // 전역 변수로 선언하여 dfs에서 접근 가능하도록 변경
int cnt = 0;          // 방문한 컴퓨터 수를 셀 전역 변수

void dfs(int here)
{
    visited[here] = 1; // 현재 노드 방문 처리

    for(int next : adj[here]) // 현재 노드와 연결된 인접 노드 탐색
    {
        if(visited[next] == 1) continue; // 이미 방문한 노드는 스킵
        cnt++;                           // 새 노드 방문 카운트 증가
        dfs(next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b; 
    cin >> a >> b;

    for(int i = 0; i < b; i++)
    {
        int c1, c2;
        cin >> c1 >> c2;
        adj[c1].push_back(c2);
        adj[c2].push_back(c1);
    }

    dfs(1); // 1번 노드부터 탐색 시작

    cout << cnt; // 1번을 통해 감염/방문된 노드 수 출력
    return 0;
}
