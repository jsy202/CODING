#include <bits/stdc++.h>

using namespace std;

int n, m;
int grid[200][200];

int ismax()
{
    int sum;
    int mx = 0;
    for(int i = 0 ; i+3 <= n ; i++)
    {
        
        for(int j = 0 ; j < m ; j++)
        {
            sum = 0;
            sum += grid[i][j];
            sum += grid[i+1][j];
            sum += grid[i+2][j];
           // cout << sum << endl;
            mx = max(sum , mx);
        }
       
    }
    for(int i = 0 ; i+3 <= m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            sum = 0;
            sum += grid[j][i];
            sum += grid[j][i+1];
            sum += grid[j][i+2];
            mx = max(sum , mx);

        }
    }
    for(int i = 0; i+2 <= n ; i++)
    {
        for(int j = 0 ; j+2 <= m ;j++)
        {
            sum = 0;
            sum += grid[i][j];
            sum += grid[i+1][j];
            sum += grid[i][j+1];
            sum += grid[i+1][j+1];
            for(int k = i ; k <= i+1 ; k++)
            {
                for(int h = j ; h <= j +1; h++)
                {
                    int p = sum - grid[k][h];
                    mx = max(mx, p);
                }
            }
        }
    }
    return mx;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int answer = ismax();
    cout << answer;

    return 0;
}
