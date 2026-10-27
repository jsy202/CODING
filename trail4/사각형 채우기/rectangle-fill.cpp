#include <iostream>

using namespace std;

// 귀납적으로 해봅시다 
// 2 * 2 - > 2 가지  2 * 3 -> 3가지 ,  2 * 4 -> 5가지 
// 2 * 5 -> 

int n;
int dp[1004];

int main() {
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3 ; i <= n ; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    cout << dp[n];

    return 0;
}
