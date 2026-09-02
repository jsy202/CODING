#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> scores;

// 점수(second) 기준 내림차순 정렬
bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    scores.resize(3, vector<int>(N));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            cin >> scores[i][j];
        }
    }

    // 각 참가자의 총점을 저장할 벡터 (first: 번호, second: 총점)
    vector<pair<int, int>> sum(N);
    for (int j = 0; j < N; j++) {
        sum[j].first = j;
        sum[j].second = 0;
    }

    // 1~3번째 대회 등수 계산 및 출력
    for (int i = 0; i < 3; i++) {
        vector<pair<int, int>> p(N);
        for (int j = 0; j < N; j++) {
            p[j].first = j;
            p[j].second = scores[i][j];
            sum[j].second += scores[i][j]; // 총점 누적
        }

        // 점수 기준 내림차순 정렬
        sort(p.begin(), p.end(), cmp);

        // 원래 참가자 순서(0번~N-1번)대로 출력하기 위한 등수 배열
        vector<int> rank(N);
        for (int k = 0; k < N; k++) {
            if (k > 0 && p[k].second == p[k - 1].second) {
                // 바로 앞 사람과 점수가 같으면 같은 등수
                rank[p[k].first] = rank[p[k - 1].first];
            } else {
                // 점수가 다르면 현재 순번(나보다 점수 큰 사람 수 + 1)
                rank[p[k].first] = k + 1;
            }
        }

        for (int j = 0; j < N; j++) {
            cout << rank[j] << (j == N - 1 ? "" : " ");
        }
        cout << "\n";
    }

    // 4번째 줄: 최종(총점) 등수 계산 및 출력
    sort(sum.begin(), sum.end(), cmp);

    vector<int> final_rank(N);
    for (int k = 0; k < N; k++) {
        if (k > 0 && sum[k].second == sum[k - 1].second) {
            final_rank[sum[k].first] = final_rank[sum[k - 1].first];
        } else {
            final_rank[sum[k].first] = k + 1;
        }
    }

    for (int j = 0; j < N; j++) {
        cout << final_rank[j] << (j == N - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}
