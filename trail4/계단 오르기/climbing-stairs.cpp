#include <iostream>

using namespace std;

int n;
int dp[1004];

int main() {
    cin >> n;

    // dp[i] 는 i 까지 올라갈수있는 방법의 수 
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4 ; i <= n ; i++)
    {
        dp[i] = (dp[i-2]  + dp[i-3]) % 10007;
    }

    cout << dp[n];

    return 0;
}