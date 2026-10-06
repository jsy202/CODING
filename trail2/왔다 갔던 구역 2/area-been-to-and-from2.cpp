#include <bits/stdc++.h> 


using namespace std;

int n;
int x[100];
char dir[100];
int visited[200005];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
    }
    int offset = 100000;
    int cur = 0;
    int cnt = 0 ;
    for(int i = 0 ; i < n ; i++)
    {   
        if(dir[i] == 'L')
        {
           while(x[i]--)
           {
            cur--;
            visited[cur+100000]++;
           if(visited[cur+100000] ==2) cnt++;
           
           }
        }
        
        if(dir[i] == 'R')
        {
            while(x[i]--){
visited[cur+100000]++;
           if(visited[cur+100000] ==2) cnt++;
           
            cur++;
            }
        }
    }

    cout << cnt ;
    return 0;
}