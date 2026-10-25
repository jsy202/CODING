#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100000];
int dp[100001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    int answer = dp[0];
    for(int i = 1 ; i < n; i++)
    {
        dp[i] = max(dp[i-1] + arr[i] , arr[i]);
        answer = max(answer , dp[i]);
    }
    
    cout << answer;
    return 0;
}
