#include <bits/stdc++.h>
using namespace std;

int n; // 맵의 크기를 전역 변수로 선언
int visited[30][30];
int a[30][30];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int cnt = 0; // 집의 개수를 셀 전역 변수

void dfs(int y, int x) {
    visited[y][x] = 1;
    cnt++; // 현재 위치의 집을 하나 카운트 (전역 변수 1 증가)
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(visited[ny][nx] == 1 || a[ny][nx] == 0) continue;
        
        // 반환값을 더할 필요 없이 그냥 재귀 호출만 하면 됨
        dfs(ny, nx);
    }
    // void 함수이므로 return 생략 가능
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n; // 변수명 a 대신 n 사용
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) {
            a[i][j] = s[j] - '0'; // 문자를 정수로 변환
        }
    }
    
    vector<int> ans; // 각 단지의 집 개수를 모을 벡터
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // 집이 있고 방문하지 않은 곳이라면 새로운 단지 시작
            if(a[i][j] == 1 && visited[i][j] == 0) {
                cnt = 0; // 새로운 단지를 탐색하기 전 카운트 초기화
                dfs(i, j); // dfs가 끝나면 cnt에 해당 단지의 집 개수가 누적됨
                ans.push_back(cnt); // 결과 저장
            }
        }
    }
    
    // 오름차순 정렬 및 출력
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int i : ans) {
        cout << i << '\n';
    }
    
    return 0;
}
