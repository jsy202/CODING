#include <bits/stdc++.h>

// 신기한 타일 뒤집기 : 왼쪽이동 -> 왼쪽으로 뒤집어요(흰색)
// 흰색 1 검은색 2
using namespace std;

int n;
int x[1000];
char dir[1000];
int arr[200005];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
    }
    int cur = 0 ;
    for(int i  = 0 ; i < n ; i ++)
    {
        if(dir[i] == 'R')
        {
            for(int j = 0 ; j < x[i]; j++)
            {
            arr[cur + 100000] = 2;
            if (j != x[i] - 1) cur += 1;
            }
        }
        else
        {
            for(int j = 0 ; j < x[i]; j++)
            {
            arr[cur + 100000] = 1;
            if(j != x[i]- 1) cur -= 1;
            }
        }
    }
    int black = 0;
    int white = 0;
    for(int i = 0 ; i < 200005 ; i ++)
    {
        if(arr[i] == 1) white ++;
        if(arr[i] == 2) black ++;
    }
    cout << white << ' ' << black;
    return 0;
}