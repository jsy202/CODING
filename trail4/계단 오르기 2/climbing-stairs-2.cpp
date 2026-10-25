#include <bits/stdc++.h>

using namespace std;

int n;
int coin[1001];
int dp[1001][4];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
    }

    for(int i = 0 ;  i <= n ; i++)
    {
        for(int j  = 0 ;  j < 4 ; j ++)
        {
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 0;
    int answer = INT_MIN;
    
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            if(j >= 1 && dp[i-1][j-1] != -1)
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + coin[i]);
            }
            if(i >= 2 && dp[i-2][j] != -1)
            {
                dp[i][j] = max(dp[i][j], dp[i-2][j] + coin[i]);
            }
        }
        
    }
    for(int j = 0; j < 4; j++)
{
    answer = max(answer, dp[n][j]);
}

    
    

    cout << answer;

    return 0;
}
