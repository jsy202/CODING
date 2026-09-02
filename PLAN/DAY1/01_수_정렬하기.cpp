#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector <int> v;
    int n ,a;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        {
            cin >> a;
            v.push_back(a);
        }
    sort(v.begin(), v.end());
    for(int i: v) cout << i << endl;
    return 0;
}
