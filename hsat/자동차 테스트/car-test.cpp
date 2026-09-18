#include <bits/stdc++.h> 

// 3대의 차량을 가지고 중앙값을 고르면 됩니다. 이때 중앙값이 m이 나오는 경우의 수를 고르는겁니다. 
// 나라면 그냥 일단 sort 박고 시작하겠음 그리고 일단 m이 첫번째나 마지막 원소면 무조건 0을 출력해야함. (서로 다르니까)
// 그리고 예시를 보면 5 2 3 1 6 -> 1 2 3 5 6 인데 여기서 3이면 2 * 2
// 즉, 나보다 작은 원소 개수 * 큰 원소 갯수 네
// sort하고 find로 위치 찾아서 처리하면 되려나 binary_search? 해볼까
// 근데 binary_search는 존재 여부만 알려주니까 위치가 필요한 이 문제에서는 lower_bound를 사용
// lower_bound는 정렬된 배열에서 해당 값 이상이 처음 나오는 위치를 반환함

using namespace std;

int n, q;
vector<int> efficiency;
vector<int> m;

int main()
{
    cin >> n >> q;

    efficiency.resize(n);

    for(int i = 0; i < n; i++)
        cin >> efficiency[i];

    m.resize(q);

    for(int i = 0; i < q; i++)
        cin >> m[i];

    // lower_bound를 사용하려면 정렬되어 있어야 함
    sort(efficiency.begin(), efficiency.end());

    for(int i = 0; i < q; i++)
    {
        // m[i] 이상인 값이 처음 등장하는 위치를 찾음
        auto it = lower_bound(
            efficiency.begin(),
            efficiency.end(),
            m[i]
        );

        // m[i]가 실제 efficiency에 존재하지 않는 경우
        if(it == efficiency.end() || *it != m[i])
        {
            cout << 0 << "\n";
            continue;
        }

        // iterator - begin()을 하면 인덱스를 구할 수 있음
        int a = it - efficiency.begin();

        // a = 나보다 작은 원소의 개수
        // n - a - 1 = 나보다 큰 원소의 개수
        //
        // 첫번째 원소라면 a = 0이라 자동으로 답 0
        // 마지막 원소라면 n - a - 1 = 0이라 자동으로 답 0
        cout << a * (n - a - 1) << "\n";
    }

    return 0;
}
        