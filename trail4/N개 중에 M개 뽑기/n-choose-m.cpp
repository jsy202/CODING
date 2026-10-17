#include <iostream>
#include <vector> 
using namespace std;

int N, M;
int visited[1000];

void go(int cnt, vector<int> &v, int a)
{
    if(cnt == M) 
    {
        for(int a : v)
        {
            cout << a << ' ';
        }
        cout << endl;
        return;
    }
    
    for(int i = a ; i <= N ; i++)
    {
        if(visited[i] == 1) continue;
        v.push_back(i);
        visited[i] = 1;
        go(cnt + 1, v , i + 1);
        visited[i] = 0;
        v.pop_back();
    }
}

int main() {
    cin >> N >> M;
    vector<int> v;
    go(0 , v , 1);
    return 0;
}
