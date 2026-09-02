#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long int n ;
    vector <pair< long long int, long long int>> v;
    cin >> n ;
    long long int a,b ;
    for( long long int i = 0 ; i<n;i++)
        {
            cin >> a >> b;
            v.push_back({a,b});
        }
    sort(v.begin(), v.end());
    for(auto a : v)
        {
            cout << a.first << ' ' << a.second << '\n';
        }
    return 0;
}
