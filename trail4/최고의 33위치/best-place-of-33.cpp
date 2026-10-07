#include <bits/stdc++.h>

using namespace std;

int N;
int grid[20][20];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    int mx = INT_MIN;
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            int sum = 0;
            for(int k = i ; k < i + 3 ; k++ )
            {
                for(int h = j ; h < j + 3; h++)
                {
                    if(j+3 > N || i +3 > N) continue;
                    sum += grid[k][h];
                }
            }
            mx = max(mx, sum);
        }
    }
    cout << mx ;
    return 0;
}
