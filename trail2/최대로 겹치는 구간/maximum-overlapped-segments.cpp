#include <iostream>

using namespace std;

int n;
int x1[100], x2[100];
int arr[500];
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }
    for(int i = 0; i < n ; i++)
    {
        x1[i] += 100;
        x2[i] += 100;
    }
    for(int i = 0 ; i < n; i++)
    {
        for(int j = x1[i]; j < x2[i]; j++)
        {
            arr[j]++;
        }
    }
    // Please write your code here.
    int mx = 0;
    for(int i = 0 ; i < 500 ; i ++)
    {
        mx = max(mx, arr[i]);
    }   
    cout << mx;
    return 0;
}