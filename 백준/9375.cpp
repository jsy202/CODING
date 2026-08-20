#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; // 테스트 케이스 수
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<string, int> mp; // 매 테스트 케이스마다 초기화

        for (int i = 0; i < n; i++) {
            string name, category;
            cin >> name >> category;
            mp[category]++; // 종류별 개수 카운트
        }

        long long ret = 1;
        // map 순회: p.second는 각 종류(category)별 의상 개수
        for (const auto& p : mp) {
            ret *= (p.second + 1); // 해당 종류를 입지 않는 경우(+1) 포함
        }

        // 아무것도 입지 않는 경우 1가지를 제외하고 출력
        cout << ret - 1 << '\n';
    }

    return 0;
}
