#include <iostream>

using namespace std;

int N;

void go(int n)
{
    if(n == N) return;
    
    cout << "HelloWorld" << endl;
    go(n+1);
}

int main() {
    cin >> N;


    go(0);
    return 0;
}