#include <bits/stdc++.h> 

using namespace std;



int N;
int x1[10];
int y_1[10];
int x2[10], y2[10];
int arr[300][300];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x1[i] >> y_1[i] >> x2[i] >> y2[i];
    }

    for(int i = 0 ; i < N ; i++)
    {
        x1[i] += 100; y_1[i] += 100;
        x2[i] += 100; y2[i] += 100;
    }

    for(int k = 0 ; k < N ; k++)
    {
    for(int i = x1[k] ; i < x2[k] ; i++)
    {
        for(int j = y_1[k] ; j < y2[k]; j++)
        {
            arr[i][j]++;
        }
    }
    }

    int cnt = 0;

    for(int i = 0 ; i < 300 ; i++)
    {
        for(int j = 0 ; j < 300; j++)
        {
            if(arr[i][j] > 0) cnt++;
        }
    }
    
    cout << cnt ;
    
    return 0;
}