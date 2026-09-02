#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int, string>> p;

    int n;
    cin >> n;

    p.resize(n);

    for(int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }

    stable_sort(p.begin(), p.end(),
        [](const auto& a, const auto& b)
        {
            return a.first < b.first;
        }
    );

    for(auto k : p)
    {
        cout << k.first << ' ' << k.second << '\n';
    }

    return 0;
}


/*
================ 람다 함수 간단 정리 ================

람다 함수 = 이름 없는 함수

기본 형태

[](매개변수)
{
    실행할 내용
};


정렬에서 자주 쓰는 형태

sort(v.begin(), v.end(),
    [](const auto& a, const auto& b)
    {
        return a < b;
    }
);


현재 코드

[](const auto& a, const auto& b)
{
    return a.first < b.first;
}

뜻:

a.first가 b.first보다 작으면
a를 b보다 앞에 둬라.

즉 pair의 first 기준 오름차순 정렬.



================ 구조 외우기 ================

[]        : 캡처
()        : 매개변수
{}        : 실행 코드

[](const auto& a, const auto& b)
{
    return 정렬조건;
}


★ sort 비교함수에서

return true;
→ a를 b보다 앞에 배치

return false;
→ a를 b보다 앞에 두지 않음



================ 자주 쓰는 예시 ================

// 오름차순
return a < b;

// 내림차순
return a > b;

// pair first 오름차순
return a.first < b.first;

// pair second 오름차순
return a.second < b.second;


// first 오름차순,
// first가 같으면 second 내림차순

if(a.first == b.first)
    return a.second > b.second;

return a.first < b.first;


================ stable_sort ================

stable_sort는 정렬 기준이 같은 값들의
"기존 순서"를 유지한다.

예)

입력

21 Junkyu
21 Dohyun
20 Sunyoung

나이(first)만 기준으로 stable_sort하면

20 Sunyoung
21 Junkyu
21 Dohyun

21끼리는 입력 순서가 유지됨.


★ 암기

람다 정렬:

[](const auto& a, const auto& b)
{
    return a를 b보다 앞에 둘 조건;
}

================================================
*/
