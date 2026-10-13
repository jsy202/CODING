#include <bits/stdc++.h>

using namespace std;

int n;
int cnt ;
vector<string> v = {"1", "22", "333", "4444"};
void go(string s)
{
    if(s.size() == n)
    {
        cnt++;
        return ;
    }
    if(s.size() > n) return;
    for(int i = 0 ; i <4 ; i++)
    {
        s += v[i];
        go(s);
        s.erase(s.size() - v[i].size());
        
    }
}

int main() {
    cin >> n;
    go("");
    cout << cnt;
    return 0;
}
