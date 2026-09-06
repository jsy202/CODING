#include <bits/stdc++.h>
using namespace std;

pair<int,int> p[54];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    // p[i].first  = 몸무게
    // p[i].second = 키
    for(int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }

    // 모든 사람 i에 대해
    for(int i = 0; i < n; i++)
    {
        // 기본 등수는 1등부터 시작
        int ret = 1;

        // 다른 모든 사람 j와 비교
        for(int j = 0; j < n; j++)
        {
            // j가 i보다 몸무게도 크고 키도 크면
            // i보다 확실히 덩치가 큰 사람이므로
            // i의 등수를 1 증가시킨다.
            if(p[j].first > p[i].first &&
               p[j].second > p[i].second)
            {
                ret++;
            }
        }

        cout << ret << ' ';
    }

    return 0;
}

/*
[핵심 아이디어]

등수 = 나보다 "몸무게와 키가 둘 다 큰 사람 수" + 1

예)
나보다 둘 다 큰 사람이 0명 -> 1등
나보다 둘 다 큰 사람이 2명 -> 3등

중요:
몸무게만 크거나 키만 큰 경우는
누가 더 덩치가 크다고 할 수 없으므로 등수에 영향 없음.

즉 반드시

p[j].first  > p[i].first
&&
p[j].second > p[i].second

둘 다 만족해야 함.


[왜 완전탐색인가?]

모든 사람 i를 기준으로
모든 사람 j와 비교한다.

N명 × N명 비교
=> O(N^2)

N <= 50이라 매우 작으므로 충분히 가능.


[외울 구조]

for(int i = 0; i < n; i++)
{
    int rank = 1;

    for(int j = 0; j < n; j++)
    {
        if(j가 i보다 조건상 우위)
            rank++;
    }

    cout << rank;
}

"나보다 우위인 사람 수 + 1 = 내 등수"

이 구조는 단순 순위/우위 비교 완전탐색 문제에서 그대로 적용 가능.
*/
