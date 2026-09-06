#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> st;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if(s == "push")
        {
            int a;
            cin >> a;
            st.push(a);
        }

        else if(s == "pop")
        {
            if(st.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << st.top() << '\n';
                st.pop();
            }
        }

        else if(s == "size")
        {
            cout << st.size() << '\n';
        }

        else if(s == "empty")
        {
            if(st.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }

        else if(s == "top")
        {
            if(st.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << st.top() << '\n';
            }
        }
    }

    return 0;
}
