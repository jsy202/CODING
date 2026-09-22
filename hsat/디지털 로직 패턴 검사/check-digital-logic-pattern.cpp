#include <bits/stdc++.h> 

// k개의 substr로 뽑아서 map으로 갯수 저장
// 이거까지는 좋은데 이거 시간 걸리는거
// 해시로 해결해야함 -> prefix hash 배열 만들기
// A * BASE^4 + B * BASE^3 + C * BASE^2
//  base = 31로 잡고 하면됨 
using namespace std;

string digital_logic;
int K, M;
int answer = 0 ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> digital_logic;
    cin >> K >> M;

    int N = digital_logic.size();

    const long long BASE = 31;
    const long long MOD = 1000000007;

    vector<long long> prefix(N + 1, 0);
    vector<long long> power(N + 1, 1);

    // prefix hash 배열 만들기
    for(int i = 0 ; i < N ; i++)
    {
        power[i + 1] = power[i] * BASE % MOD;

        int value = digital_logic[i] - '0' + 1;

        prefix[i + 1] =
            (prefix[i] * BASE + value) % MOD;
    }

    unordered_map<long long, int> mp;

    for(int i = 0 ; i <= N - K ; i++)
    {
        // substr(i, K) 대신 길이 K짜리 구간의 hash값을 가져옴
        long long hash =
            (prefix[i + K]
            - prefix[i] * power[K] % MOD
            + MOD) % MOD;

        mp[hash]++;

        if(mp[hash] >= M)
        {
            answer = 1;
            break;
        }
    }

    cout << answer ;
    return 0;
}