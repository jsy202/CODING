#include <iostream>

using namespace std;

int N;
int x[100], y[100];
int arr[200][200];
int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    for(int i = 0 ; i < N ; i++)
    {
        x[i] += 100;
        y[i] += 100;
    }

    for(int i = 0 ; i < N ; i++)
    {
        for(int j = x[i]; j < x[i]+8 ; j++)
        {
                for(int k = y[i]; k < y[i]+8 ; k++)
                {
                    arr[j][k] ++;
                }
        }
    }
    int cnt = 0;
    for(int i = 0 ; i < 200 ; i++)
    {
        for(int j = 0 ; j < 200 ; j++)
        {
            if(arr[i][j] > 0) cnt++;
        }
    }
    cout << cnt ;
    return 0;
}