#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int grid[100][100];
// 행복한 수열 : 

int ishappy()
{
    if (m == 1) return 2 * n;

    int answer = 0;

    // 가로 행 검사
    for(int i = 0 ; i < n ; i++)
    {
        int cnt = 1;
        int max_cnt = 1;
        for(int j = 1 ; j < n; j++)
        {
            if(grid[i][j] == grid[i][j-1]) cnt++; 
            else cnt = 1;

            max_cnt = max(max_cnt, cnt);
        }
        if(max_cnt >= m) answer++;    
    }

    // 세로 열 검사
    for(int i = 0 ; i < n ; i++)
    {
        int cnt = 1;
        int max_cnt = 1;
        for(int j = 1 ; j < n; j++)
        {
            if(grid[j][i] == grid[j-1][i]) cnt++;
            else cnt = 1;

            max_cnt = max(max_cnt, cnt);
        }
        if(max_cnt >= m) answer++;  
    }
    
    return answer;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int a = ishappy();

    cout << a;

    return 0;
}
