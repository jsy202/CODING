#include <iostream>

using namespace std;

int n;
long long dp[1005];
// 이전 dp 사각형에서 옆으로 한칸 or 두칸 or 세칸씩 생긴다고 보면됨 + 걍 ㅈㄴ 어려움 다시 풀기 
int main() {
    cin >> n;
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 7;
    dp[3] = 22;
    for(int i = 4 ; i <=n ; i++)
    {
        dp[i] = (dp[i-1] * 3  + dp[i-2]  - dp[i-3] + 1000000007 ) % 1000000007; // 뺄셈으로 인한 음수 방지용
    }

    cout << dp[n];
    return 0;
}
