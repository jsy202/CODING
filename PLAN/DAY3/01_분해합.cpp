#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a; cin >> a;
    int answer =0;
    for(int i = 0 ; i< 1000000; i++)
        {
            int sum = i;
            string s = to_string(i);
            for(int j = 0 ; j < s.size() ; j++)
                {
                    sum += (s[j]- '0');    
                }
            if(sum == a) 
            {
                answer = i;
                break;
            }
            
        }
    cout << answer;
    return 0;
}
