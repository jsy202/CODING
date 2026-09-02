#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> v(n);

    for(int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    while(q--)
    {
        int m;
        cin >> m;

        auto it = lower_bound(v.begin(), v.end(), m);

        if(it == v.end() || *it != m)
        {
            cout << 0 << '\n';
            continue;
        }

        long long left = it - v.begin();
        long long right = n - left - 1;

        cout << left * right << '\n';
    }
}


/*
================ lower_bound / upper_bound 정리 ================

★ 반드시 정렬된 배열에서 사용

sort(v.begin(), v.end());


1. lower_bound

lower_bound(v.begin(), v.end(), x);

→ x "이상"인 값이 처음 나오는 위치

예)
v = {1, 2, 3, 3, 3, 5, 7}

lower_bound(..., 3)

              ↓
1 2 [3] 3 3 5 7
     index = 2


사용법

auto it = lower_bound(v.begin(), v.end(), x);

int idx = it - v.begin();

→ iterator - begin() 하면 인덱스가 나옴.



2. upper_bound

upper_bound(v.begin(), v.end(), x);

→ x "초과"인 값이 처음 나오는 위치

예)
v = {1, 2, 3, 3, 3, 5, 7}

upper_bound(..., 3)

                    ↓
1 2 3 3 3 [5] 7
           index = 5



================ 개수 구하기 ================

v = {1, 2, 3, 3, 3, 5, 7}


① x보다 작은 값 개수

lower_bound(v.begin(), v.end(), x) - v.begin();

x = 3이면

{1, 2}

→ 2개



② x 이하 값 개수

upper_bound(v.begin(), v.end(), x) - v.begin();

x = 3이면

{1, 2, 3, 3, 3}

→ 5개



③ x보다 큰 값 개수

v.end() - upper_bound(v.begin(), v.end(), x);

x = 3이면

{5, 7}

→ 2개



④ x 이상 값 개수

v.end() - lower_bound(v.begin(), v.end(), x);

x = 3이면

{3, 3, 3, 5, 7}

→ 5개



⑤ x의 개수

upper_bound(v.begin(), v.end(), x)
-
lower_bound(v.begin(), v.end(), x);

x = 3이면

3이 3개 있으므로 → 3



================ 존재 여부 확인 ================

auto it = lower_bound(v.begin(), v.end(), x);

if(it != v.end() && *it == x)
{
    // x가 존재
}
else
{
    // x가 없음
}


================ 외우기 ================

lower_bound = 이상
upper_bound = 초과

lower = >=
upper = >

작은 개수 = lower - begin
이하 개수 = upper - begin
큰 개수 = end - upper
이상 개수 = end - lower

같은 값 개수 = upper - lower


★ 유형

"정렬된 배열에서
x보다 작은 개수 / 큰 개수 /
x가 몇 개 있는지 /
x가 존재하는지
여러 번 물어본다"

→ lower_bound / upper_bound 의심


시간복잡도

sort : O(N log N)

lower_bound : O(log N)
upper_bound : O(log N)

질의 Q개라면

O(N log N + Q log N)

==============================================================
*/
