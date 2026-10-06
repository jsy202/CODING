#include <iostream>

using namespace std;

int x1[3], y_1[3];
int x2[3], y2[3];
int arr[2000][2000];
int main() {
    cin >> x1[0] >> y_1[0] >> x2[0] >> y2[0];
    cin >> x1[1] >> y_1[1] >> x2[1] >> y2[1];
    cin >> x1[2] >> y_1[2] >> x2[2] >> y2[2];

    for(int i = 0 ; i < 3 ; i++)
    {
        x1[i] += 1000;
        x2[i] += 1000;
        y_1[i] += 1000;
        y2[i] += 1000;
    }

    for(int i = 0 ; i < 2 ; i++)
    {
        for(int j = x1[i]; j < x2[i] ; j++)
        {
            for(int k = y_1[i]; k < y2[i]; k++)
            {
                arr[j][k]++;
            }
        }
    }

    for(int j = x1[2]; j < x2[2] ; j++)
        {
            for(int k = y_1[2]; k < y2[2]; k++)
            {
                arr[j][k] = 0;
            }
        }
    int cnt = 0 ;
    for(int i = 0 ; i < 2000; i++)
    {
        for(int j = 0 ; j < 2000; j++)
        {
            if(arr[i][j] != 0) cnt++;
        }
    }
    cout << cnt ;
    return 0;
}