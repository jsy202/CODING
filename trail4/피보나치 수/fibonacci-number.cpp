#include <iostream>

using namespace std;

int N;
int pib[46];

int main() {
    cin >> N;

    pib[0] = 1; pib[1] =1; pib[2] = 2;


    for(int i = 2 ; i < 45 ; i++)
    {
        pib[i] = pib[i-1] + pib[i-2];
    }
    cout << pib[N-1];

    return 0;
}
