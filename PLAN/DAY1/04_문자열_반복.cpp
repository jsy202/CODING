#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, r; cin >> t;
    while(t--)
        {
            cin >> r;
            string s; cin >> s;
            for(char ch : s)
                {
                    for(int i = 0 ; i < r; i++)
                        {
                            cout << ch;
                        }
                }
            cout << "\n";
        }
    return 0;
}
