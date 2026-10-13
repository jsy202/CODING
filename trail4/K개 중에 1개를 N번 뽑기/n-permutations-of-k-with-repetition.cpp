#include <iostream>
#include <vector> 
using namespace std;

int K, N;

void go(int n, vector<int> v)
{
    if(n == N) {
        for(int j : v) {
            cout << j << ' ' ;
            
        }
        cout << endl;
        return ;
    }
    for(int i = 1 ; i <= K ; i++){
    v.push_back(i);
    go( n + 1, v);
    v.pop_back();
    }
}

int main() {
    cin >> K >> N;

    vector<int> v;
    go(0 , v);

    return 0;
}
